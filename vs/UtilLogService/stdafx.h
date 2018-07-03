// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
#include <utils\utils.h>
#include <utils\ShareMemory.h>
#include <utils\LogFile.h>
#include <utils\Thread.h>
#include <utils\service.h>
using namespace UTILS::API;
#pragma comment(lib, "utils/utils.lib")

#include <UtilLog\include\UtilLog.h>
#include <UtilLog\include\logserver.h>
#pragma comment(lib,"UtilLog/lib/UtilLog.lib")