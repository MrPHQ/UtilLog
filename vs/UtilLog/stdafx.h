// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>



// TODO: reference additional headers your program requires here
#include "../include/UtilLog.h"
#include "../include/logger.h"

#include <utils\utils.h>
#include <utils\ShareMemory.h>
#include <utils\LogFile.h>
#include <utils\Thread.h>
using namespace UTILS::API;
#pragma comment(lib, "utils/utils.lib")

#include "InnerDef.h"

extern HINSTANCE ghIns;