#include "stdafx.h"
#include "Main.h"


CMain::CMain()
{
	m_bStartUp = FALSE;
}


CMain::~CMain()
{
}

CMain& CMain::GetInstance()
{
	static CMain ins;
	return ins;
}

int CMain::Start()
{
	if (m_bStartUp){
		return 0;
	}
	int ret = m_logServer.Start();
	if (ret != 0){
		return -1;
	}
	m_bStartUp = TRUE;
	return 0;
}

void CMain::Stop()
{
	if (!m_bStartUp){
		return;
	}
	m_logServer.Stop();
	m_bStartUp = FALSE;
}

void CMain::Run(HANDLE hExit)
{
	while (m_bStartUp) {
		if (nullptr != hExit) {
			DWORD dwWait = UTILS::API::fnWaitForSingleObject(hExit, 10);
			if (WAIT_OBJECT_0 == dwWait) {
				m_bStartUp = FALSE;
				return;
			}
		}
		else {
			Sleep(10);
		}
	}
}