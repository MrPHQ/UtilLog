#include "stdafx.h"
#include "LogFile.h"


CLogFileMgr::CLogFileMgr()
{
}


CLogFileMgr::~CLogFileMgr()
{
}

CLogFileMgr& CLogFileMgr::GetInstance()
{
	static CLogFileMgr mgr;
	return mgr;
}

int CLogFileMgr::Open(DWORD nHead, const char* file, unsigned int uiDays, unsigned int uiPerFileSize)
{
	if (file == nullptr){
		return -1;
	}
	UTILS::CAutoLock lock(&m_lock);
	char szFile[MAX_PATH];
	_snprintf_s(szFile, _TRUNCATE, "%s", file);
	UTILS::API::StripPath(szFile);
	if (strlen(szFile) <= 0){
		return -2;
	}
	auto it = m_mapLogFiles.find(szFile);
	if (it == m_mapLogFiles.end()){
		CLogFile* p = new CLogFile();
		if (p == nullptr){
			return -3;
		}
		if (p->Open(nHead, szFile, uiDays, uiPerFileSize) != 0){
			delete p;
			return -4;
		}
		auto itRet = m_mapLogFiles.emplace(szFile, p);
		if (itRet.second){
			it = itRet.first;
		}
	}
	if (it == m_mapLogFiles.end())
	{
		return -5;
	}
	return 0;
}

void CLogFileMgr::Close(const char* file)
{
	if (file == nullptr){
		return ;
	}
	UTILS::CAutoLock lock(&m_lock);
	char szFile[MAX_PATH];
	_snprintf_s(szFile, _TRUNCATE, "%s", file);
	UTILS::API::StripPath(szFile);
	if (strlen(szFile) <= 0){
		return ;
	}
	auto it = m_mapLogFiles.find(szFile);
	if (it != m_mapLogFiles.end()){
		it->second->Close();
		delete it->second;
		m_mapLogFiles.erase(it);
	}
}

void CLogFileMgr::Write(const char* file, const char* log)
{
	if (file == nullptr){
		return;
	}
	UTILS::CAutoLock lock(&m_lock);
	char szFile[MAX_PATH];
	_snprintf_s(szFile, _TRUNCATE, "%s", file);
	UTILS::API::StripPath(szFile);
	if (strlen(szFile) <= 0){
		return;
	}
	auto it = m_mapLogFiles.find(szFile);
	if (it != m_mapLogFiles.end()){
		it->second->Write(log);
	}
}

CLogFile::CLogFile()
{
}


CLogFile::~CLogFile()
{
}

int CLogFile::Open(DWORD nHead, const char* file, unsigned int uiDays, unsigned int uiPerFileSize)
{
	if (file == nullptr){
		return -1;
	}
	char szFile[MAX_PATH],szLogDir[128];
	_snprintf_s(szFile, _TRUNCATE, "%s", file);
	UTILS::API::StripPath(szFile);
	if (strlen(szFile) <= 0){
		return -2;
	}
	Strcpy(szLogDir, 128, szFile);
	UTILS::API::RemoveExtension(szLogDir);
	if (strlen(szLogDir) <= 0){
		return -3;
	}
	char szPath[MAX_PATH];
	_snprintf_s(szPath, _TRUNCATE, "%s\\%s\\%s\\%s", GetCurrentPath(ghIns), LOG_FOLDER_NAME, szLogDir, szFile);
	UTILS::API::CreateFoldersFromFilePath(szPath);
	int ret = m_logFile.Open(UTILS::LOG_FILE_MODE_ASYNC_IN, nHead, szPath, uiDays, uiPerFileSize);
	MSG_INFO("log file open [%s] err:%d", szPath,ret);
	if (ret != 0){
		return -4;
	}
	return 0;
}

void CLogFile::Close()
{
	m_logFile.Close();
}

void CLogFile::Write(const char* log)
{
	if (log == nullptr){
		return;
	}
	OutputDebugString(log);
	m_logFile.Write(log);
}