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

/**
@brief ��������.
*/
namespace UTIL_LOG
{
	enum CMD_TYPE
	{
		CMD_TYPE_NONE = 0,
		/**< �µ���־�ļ� .*/
		CMD_TYPE_NEW_LOG = 1,
		/**< ��־���� .*/
		CMD_TYPE_LOG_CONTENT = 2,
	};
}
#endif