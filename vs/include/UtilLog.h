#ifndef __UTIL_LOG__
#define __UTIL_LOG__

#ifdef UTIL_LOG_EXPORTS
#define UTIL_LOG_CAPI extern "C" __declspec(dllexport)
#else
#define UTIL_LOG_CAPI extern "C" __declspec(dllimport)	
#endif

#ifdef UTIL_LOG_EXPORTS
#define UTIL_LOG_CPPAPI __declspec(dllexport)
#else
#define UTIL_LOG_CPPAPI __declspec(dllimport)	
#endif

#endif