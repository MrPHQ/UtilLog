#pragma once

class CLogFile;
class CLogFileMgr
{
private:
	CLogFileMgr();
	~CLogFileMgr();
public:
	/**
	@brief 获取类操作实例.
	*/
	static CLogFileMgr& GetInstance();
	/**
	@brief 初始化新的日志文件.
	*/
	int Open(DWORD nHead, const char* file, unsigned int uiDays, unsigned int uiPerFileSize);
	void Close(const char* file);

	/**
	@brief 写日志.
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
	@brief 初始化新的日志文件.
	*/
	int Open(DWORD nHead, const char* file, unsigned int uiDays, unsigned int uiPerFileSize);
	void Close();
	/**
	@brief 写日志.
	*/
	void Write(const char* log);
private:
	UTILS::CLogFile m_logFile;
};

