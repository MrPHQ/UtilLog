#include "stdafx.h"
#include "../include/logserver.h"

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
			ProcPicData(lpPacket);
		}, nullptr);

		ZeroMemory(&stSMP, sizeof(UTILS::SHARE_MEMORY_PROPERTY));
		Sprintf(stSMP.szShareSegName, sizeof(stSMP.szShareSegName), "%s%s", UTIL_SM_CONTROL, UTIL_SM_CTRL_FLAG_SHARESEG);
		Sprintf(stSMP.szChangeEventName, sizeof(stSMP.szChangeEventName), "%s%s", UTIL_SM_CONTROL, UTIL_SM_CTRL_FLAG_EVENT);
		Sprintf(stSMP.szMutexName, sizeof(stSMP.szMutexName), "%s%s", UTIL_SM_CONTROL, UTIL_SM_CTRL_FLAG_MUTEX);
		m_smControl.Init(UTILS::CT_READER, &stSMP, 1024 * 8);
		m_smControl.RegisterDataCallback([this](UTILS::CommunicatorPacket_t* lpPacket, void* pUsrPar) {
			ProcPicData(lpPacket);
		}, nullptr);

		m_bInit = TRUE;

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

	void CLogServer::ProcPicData(UTILS::CommunicatorPacket_t*)
	{

	}
}