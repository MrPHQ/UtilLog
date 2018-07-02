#include "stdafx.h"
#include "../include/logger.h"
#include "../inc/log.pb.h"

namespace UTIL_LOG
{
	CLogger::CLogger()
	{
		m_bOpen = FALSE;
	}

	CLogger::~CLogger()
	{

	}

	int CLogger::Open(DWORD nHead, const char* file, unsigned int uiDays, unsigned int uiPerFileSize)
	{
		if (m_bOpen){
			return 0;
		}

		if (nullptr == file || strlen(file) <= 0){
			return -1;
		}

		BYTE buff[1024];
		int iDataLen = 0;
		UTILS::SHARE_MEMORY_PROPERTY stSMP;
		ZeroMemory(&stSMP, sizeof(UTILS::SHARE_MEMORY_PROPERTY));
		Sprintf(stSMP.szShareSegName, sizeof(stSMP.szShareSegName), "%s%s", UTIL_SM_LOG, UTIL_SM_FLAG_SHARESEG);
		Sprintf(stSMP.szChangeEventName, sizeof(stSMP.szChangeEventName), "%s%s", UTIL_SM_LOG, UTIL_SM_FLAG_EVENT);
		Sprintf(stSMP.szMutexName, sizeof(stSMP.szMutexName), "%s%s", UTIL_SM_LOG, UTIL_SM_FLAG_MUTEX);
		if (m_smLog.Init(UTILS::CT_WRITER, &stSMP, 1024 * 1024) != 0){
			MSG_INFO("error, line:%d", __LINE__);
			return -2;
		}
		ZeroMemory(&stSMP, sizeof(UTILS::SHARE_MEMORY_PROPERTY));
		Sprintf(stSMP.szShareSegName, sizeof(stSMP.szShareSegName), "%s%s", UTIL_SM_CONTROL, UTIL_SM_CTRL_FLAG_SHARESEG);
		Sprintf(stSMP.szChangeEventName, sizeof(stSMP.szChangeEventName), "%s%s", UTIL_SM_CONTROL, UTIL_SM_CTRL_FLAG_EVENT);
		Sprintf(stSMP.szMutexName, sizeof(stSMP.szMutexName), "%s%s", UTIL_SM_CONTROL, UTIL_SM_CTRL_FLAG_MUTEX);
		if (m_smControl.Init(UTILS::CT_WRITER, &stSMP, 1024 * 8) != 0){
			MSG_INFO("error, line:%d", __LINE__);
			return -3;
		}

		MsgLogFile logFile;
		logFile.set_headmode(nHead);
		logFile.set_file(file);
		logFile.set_day(uiDays);
		logFile.set_size(uiPerFileSize);

		iDataLen = logFile.ByteSizeLong();
		if (!logFile.SerializeToArray(buff, 1024)){
			MSG_INFO("error, line:%d", __LINE__);
			return -4;
		}

		MsgLogControl logCtrl;
		logCtrl.set_cmd(MsgLogControl::CMD_TYPE_NEW_LOG);
		logCtrl.set_cmdflag(GetTickCount());
		logCtrl.set_timestamp(GetTickCount());
		logCtrl.set_data(buff, iDataLen);
		logCtrl.set_datalen(iDataLen);
		if (!logCtrl.SerializeToArray(buff, 1024)){
			MSG_INFO("error, line:%d", __LINE__);
			return -5;
		}
		m_strFile = file;
		iDataLen = logCtrl.ByteSizeLong();
		WriteCmdData(buff, iDataLen);

		m_tbThread.Init(1024, 1024, TRUE, TRUE);
		m_tbThread.Start([this](BOOL& bRun, HANDLE hWait, void* context){
			BYTE buff[1024 * 512], byData[1024 * 512];
			int iBuffLen = 1024 * 512, iDataLen = 0;
			UTILS::CommunicatorPacket_t* pInfo;
			while (bRun)
			{
				WaitForSingleObject(hWait, 100);
				if (!bRun){
					break;
				}

				MsgLogContent logContent;
				do
				{
					iDataLen = m_tbThread.ReadData(buff, iBuffLen);
					if (iDataLen <= 0){
						break;
					}
					logContent.Clear();
					logContent.set_file(m_strFile.data());
					logContent.set_content((const char*)buff, iDataLen);
					iDataLen = logContent.ByteSizeLong();
					if (logContent.SerializeToArray(byData, 1024 * 512)){
						pInfo = (UTILS::CommunicatorPacket_t*)buff;
						ZeroMemory(pInfo, sizeof(UTILS::CommunicatorPacket_t));
						pInfo->dwFlag = PROC_FLAG;
						pInfo->iLen = iDataLen;
						memcpy(pInfo->bData, buff, min(iDataLen, 1024 * 512 - sizeof(UTILS::CommunicatorPacket_t)));
						m_smLog.WriteData(pInfo);
					}
					else{
						MSG_INFO("error, line:%d", __LINE__);
					}
				} while (true);
			}
		});
		m_bOpen = TRUE;
		return 0;
	}

	void CLogger::Close()
	{
		if (!m_bOpen){
			return;
		}
		m_bOpen = FALSE;
		m_tbThread.Cancel();
		m_tbThread.Stop(500);
		m_tbThread.UnInit();
		m_smControl.UnInit();
		m_smLog.UnInit();
	}

	void CLogger::Write(const char* pFormat, ...)
	{
		if (nullptr == pFormat){
			return;
		}
		char buff[1024 * 256];
		va_list args;
		va_start(args, pFormat);
		_vsnprintf_s(buff, 1024 * 256 - sizeof(UTILS::CommunicatorPacket_t) - 1, pFormat, args);
		va_end(args);
		m_tbThread.WriteData(buff, strlen(buff));
	}

	void CLogger::WriteEx(const char* file, int line, const char* pFormat, ...)
	{
		if (nullptr == file || nullptr == pFormat){
			return;
		}

	}

	int CLogger::WriteCmdData(void* pData, int len)
	{
		if (nullptr == pData){
			return -1;
		}
		BYTE buff[1024 * 16];
		UTILS::CommunicatorPacket_t* pInfo = (UTILS::CommunicatorPacket_t*)buff;
		ZeroMemory(pInfo, sizeof(UTILS::CommunicatorPacket_t));
		pInfo->dwFlag = PROC_FLAG;
		pInfo->iLen = len;
		memcpy(pInfo->bData, pData, len);
		m_smControl.WriteData(pInfo);
		return 0;
	}
}