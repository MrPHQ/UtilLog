#include "stdafx.h"
#include "../include/logger.h"

namespace UTIL_LOG
{
	CLogger::CLogger()
	{

	}

	CLogger::~CLogger()
	{

	}

	int CLogger::Open(DWORD nHead, const char* file, unsigned int uiDays, unsigned int uiPerFileSize)
	{
		return 0;
	}

	void CLogger::Close()
	{

	}

	void CLogger::Write(const char* pFormat, ...)
	{

	}

	void CLogger::WriteEx(const char* file, int line, const char* pFormat, ...)
	{

	}
}