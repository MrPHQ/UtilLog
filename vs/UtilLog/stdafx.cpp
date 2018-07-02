// stdafx.cpp : source file that includes just the standard includes
// UtilLog.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
HINSTANCE ghIns = NULL;

#ifdef _DEBUG
#pragma comment(lib,"google/protobuf/lib/libprotocd.lib")
#pragma comment(lib,"google/protobuf/lib/libprotobufd.lib")
#else
#pragma comment(lib,"google/protobuf/lib/libprotoc.lib")
#pragma comment(lib,"google/protobuf/lib/libprotobuf.lib")
#endif