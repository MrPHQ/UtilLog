// UtilLogService.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Main.h"

#ifdef _WIN32
//共享内存数据段
#pragma data_seg("UtilLogService_shared_data")
static int g_dwProcessId = 0;//主服务进程ID
static int g_dwProcessWatchDogId = 0;//看管服务进程ID
static BOOL g_bMainStop = 0;
static BOOL g_bWatchDogStop = 0;
#pragma data_seg()
#pragma comment(linker,"/section:UtilLogService_shared_data,rws")
#endif

void Run(int argc, _TCHAR* argv[]);

int _tmain(int argc, _TCHAR* argv[])
{
#ifndef _DEBUG
	Run(argc, argv);
#else
	if (CMain::GetInstance().Start() != 0) {
		return -1;
	}
	CMain::GetInstance().Run(nullptr);
#endif
	return 0;
}

void Run(int argc, _TCHAR* argv[]) {

	UTILS::SERVICE::SERVICE_INFO stServer, stWatchDog;
	UTILS::SERVICE::SERVER_STATUS stStatus;
	Memset(&stStatus, 0, sizeof(UTILS::SERVICE::SERVER_STATUS));
	stStatus.bStopMainProcess = &g_bMainStop;
	stStatus.bStopWatchDogProccess = &g_bWatchDogStop;
	stStatus.iMainProcessID = &g_dwProcessId;
	stStatus.iWatchDogProcessID = &g_dwProcessWatchDogId;

	Memset(&stServer, 0, sizeof(UTILS::SERVICE::SERVICE_INFO));
	Sprintf(stServer.szName, sizeof(stServer.szName), "UtilLogService");
	Sprintf(stServer.szDisplayName, sizeof(stServer.szDisplayName), "UtilLogService");
	Sprintf(stServer.szDescribe, sizeof(stServer.szDescribe), "UtilLogService Main Service");
	Memset(&stWatchDog, 0, sizeof(UTILS::SERVICE::SERVICE_INFO));
	Sprintf(stWatchDog.szName, sizeof(stWatchDog.szName), "UtilLogServiceWatchDog");
	Sprintf(stWatchDog.szDisplayName, sizeof(stWatchDog.szDisplayName), "UtilLogServiceWatchDog");
	Sprintf(stWatchDog.szDescribe, sizeof(stWatchDog.szDescribe), "UtilLogServiceWatchDog Main Service");
	int err = UTILS::SERVICE::Service::Init(&stServer, &stWatchDog,
		&stStatus,
		[]() -> int {return CMain::GetInstance().Start(); },
		[]() {CMain::GetInstance().Stop(); },
		[](HANDLE hExit) {CMain::GetInstance().Run(hExit); });
	err = UTILS::SERVICE::Service::AnalyseCmd(argc, argv);
}