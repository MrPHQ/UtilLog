#pragma once

class CLogFile;
class CLogFileMgr
{
private:
	CLogFileMgr();
	~CLogFileMgr();
public:
	/**
	@brief ��ȡ�����ʵ��.
	*/
	static CLogFileMgr& GetInstance();
	/**
	@brief ��ʼ���µ���־�ļ�.
	*/
	int Open(DWORD nHead, const char* file, unsigned int uiDays, unsigned int uiPerFileSize);
	void Close(const char* file);

	/**
	@brief д��־.
	*/
	void Write(const char* file, const char* log);

private:
	/**<  .*/
	std::map<std::string, CLogFile*> m_mapLogFiles;
	UTILS::CCritSec m_lock;
};

class CLogFile
{
	friend class CLogFileMgr;
private:
	CLogFile();
	~CLogFile();
	/**
	@brief ��ʼ���µ���־�ļ�.
	*/
	int Open(DWORD nHead, const char* file, unsigned int uiDays, unsigned int uiPerFileSize);
	void Close();
	/**
	@brief д��־.
	*/
	void Write(const char* log);
private:
	UTILS::CLogFile m_logFile;
};

