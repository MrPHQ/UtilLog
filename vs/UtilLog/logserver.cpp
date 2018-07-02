#include "stdafx.h"
#include "../include/logserver.h"
#include "LogFile.h"
#include "../inc/log.pb.h"
namespace UTIL_LOG
{
	CLogServer::CLogServer()
	{
		m_bInit = FALSE;
	}

	CLogServer::~CLogServer()
	{

	}

	int CLogServer::Start()
	{
		if (m_bInit)
			return 0;

		UTILS::SHARE_MEMORY_PROPERTY stSMP;
		ZeroMemory(&stSMP, sizeof(UTILS::SHARE_MEMORY_PROPERTY));
		Sprintf(stSMP.szShareSegName, sizeof(stSMP.szShareSegName),"%s%s", UTIL_SM_LOG, UTIL_SM_FLAG_SHARESEG);
		Sprintf(stSMP.szChangeEventName, sizeof(stSMP.szChangeEventName),"%s%s", UTIL_SM_LOG, UTIL_SM_FLAG_EVENT);
		Sprintf(stSMP.szMutexName, sizeof(stSMP.szMutexName),"%s%s", UTIL_SM_LOG, UTIL_SM_FLAG_MUTEX);
		m_smLog.Init(UTILS::CT_READER, &stSMP, 1024 * 1024);
		m_smLog.RegisterDataCallback([this](UTILS::CommunicatorPacket_t* lpPacket, void* pUsrPar) {
			ProcPicContentData(lpPacket);
		}, nullptr);

		ZeroMemory(&stSMP, sizeof(UTILS::SHARE_MEMORY_PROPERTY));
		Sprintf(stSMP.szShareSegName, sizeof(stSMP.szShareSegName), "%s%s", UTIL_SM_CONTROL, UTIL_SM_CTRL_FLAG_SHARESEG);
		Sprintf(stSMP.szChangeEventName, sizeof(stSMP.szChangeEventName), "%s%s", UTIL_SM_CONTROL, UTIL_SM_CTRL_FLAG_EVENT);
		Sprintf(stSMP.szMutexName, sizeof(stSMP.szMutexName), "%s%s", UTIL_SM_CONTROL, UTIL_SM_CTRL_FLAG_MUTEX);
		m_smControl.Init(UTILS::CT_READER, &stSMP, 1024 * 8);
		m_smControl.RegisterDataCallback([this](UTILS::CommunicatorPacket_t* lpPacket, void* pUsrPar) {
			ProcPicCmdData(lpPacket);
		}, nullptr);

		m_bInit = TRUE;

		m_tbThread.Init(1024, 1024*4, TRUE, TRUE);
		m_tbThread.Start([this](BOOL& bRun, HANDLE hWait, void* context){
			BYTE buff[1024 * 256];
			BYTE* pBuff = buff;
			int iBuffLen = 1024 * 256;
			int iDataLen = 0, iNeedLen = 0;

			while (bRun)
			{
				WaitForSingleObject(hWait, 100);
				if (!bRun){
					break;
				}

				do
				{
					if (NULL == pBuff){
						break;
					}
					iNeedLen = 0;
					iDataLen = m_tbThread.ReadData(pBuff, 1, &iNeedLen);
					if (iNeedLen <= 0){
						break;
					}
					if (iNeedLen >= iBuffLen)
					{
						if (NULL != pBuff && (iBuffLen > 1024 * 256)) {
							delete[] pBuff;
							pBuff = NULL;
							iBuffLen = 0;
						}
						if (iNeedLen > 1024 * 1024 * 64){
							iNeedLen = 1024 * 1024 * 64;
						}
						iBuffLen = PAD_SIZE(iNeedLen);
						pBuff = new BYTE[iBuffLen];
					}
					if (NULL == pBuff){
						break;
					}
					iDataLen = m_tbThread.ReadData(pBuff, iBuffLen);
					if (iDataLen <= 0){
						break;
					}
					ThreadData(pBuff, iBuffLen);
				} while (true);
			}

		});

		DWORD dwLogHeadFlag = 0;
		dwLogHeadFlag |= UTILS::LOG_FILE_HEAD_TIME;
		dwLogHeadFlag |= UTILS::LOG_FILE_HEAD_PROC_NAME;
		dwLogHeadFlag |= UTILS::LOG_FILE_HEAD_PROC_ID;
		dwLogHeadFlag |= UTILS::LOG_FILE_HEAD_THREAD_ID;
		dwLogHeadFlag |= UTILS::LOG_FILE_HEAD_FILE_NAME;
		dwLogHeadFlag |= UTILS::LOG_FILE_HEAD_FILE_LINE;
		char szFile[256];
		int iCnt = 0;
		_snprintf_s(szFile, _TRUNCATE, "%s\\utilsTest.log", UTILS::API::GetCurrentPath());
		UTILS::LOG_INIT(UTILS::LOG_FILE_MODE_ASYNC_IN, dwLogHeadFlag, szFile, 2, 1024 * 1024);
		UTILS::LOG_WRITE_EX("Æô¶¯.");

		return 0;
	}

	void CLogServer::Stop()
	{
		if (!m_bInit){
			return;
		}
		m_bInit = FALSE;
		m_smLog.UnInit();
		m_smControl.UnInit();
	}

	void CLogServer::ProcPicCmdData(UTILS::CommunicatorPacket_t* pData)
	{
		if (nullptr == pData){
			return;
		}
		MsgLogFile file;
		if (!file.ParseFromArray(pData->bData, pData->iLen)){
			MSG_INFO("error, line:%d", __LINE__);
			return;
		}
		CLogFileMgr::GetInstance().Open(file.headmode(),file.file().data(),file.day(), file.size());
	}

	void CLogServer::ProcPicContentData(UTILS::CommunicatorPacket_t* pData)
	{
		if (nullptr == pData){
			return;
		}
		m_tbThread.WriteData(pData->bData, pData->iLen);
	}

	void CLogServer::ThreadData(BYTE* pData, int len)
	{
		if (nullptr == pData || len <= 0){
			return;
		}
		MsgLogContent log;
		if (!log.ParseFromArray(pData, len)){
			MSG_INFO("error, line:%d",__LINE__);
			return;
		}
		CLogFileMgr::GetInstance().Write(log.file().data(), log.content().data());
	}
}