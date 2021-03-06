#ifndef __UTILLOG_LOGGER__
#define __UTILLOG_LOGGER__

namespace UTIL_LOG
{
	/**
	\brief
		日志文件记录头信息.
	*/
	enum LOG_HEAD {
		/**< 写时间 */
		LOG_HEAD_TIME = 0x01,
		/**< 写进程名 */
		LOG_HEAD_PROC_NAME = 0x02,
		/**< 写进程ID */
		LOG_HEAD_PROC_ID = 0x04,
		/**< 写线程ID */
		LOG_HEAD_THREAD_ID = 0x08,
		/**< 写文件名 */
		LOG_HEAD_FILE_NAME = 0x10,
		/**< 写行号 */
		LOG_HEAD_FILE_LINE = 0x20,
	};

	/**
	@brief 日志客户端.
	*/
	class UTIL_LOG_CPPAPI CLogger
	{
	public:
		CLogger();
		~CLogger();
		/**
		\brief
			打开文件
			注意: 日志指定的日志文件不存在,则会创建,如果已经存在,则打开后直接定位到文件末尾.
		\param nHead
			日志文件记录头信息. 参见LOG_HEAD
		\param file
			日志文件(文件名).
		\param uiDays
			存储天数
		\param uiPerFileSize
			每个日志文件最大容量. 字节.
		\return
			Error.h
		*/
		int Open(DWORD nHead, const char* file, unsigned int uiDays, unsigned int uiPerFileSize);
		/**
		\brief
			关闭文件
		*/
		void Close();
		/**
		\brief 写入日志.
			注意最大字符串长度 [1024*256]
		*/
		void Write(const char* pFormat, ...);
		/**
		\brief
			写入日志.
		\param file
			日志位置所在文件.
		\param line
			日志所在位置文件行号.
		*/
		void WriteEx(const char* file, int line, const char* pFormat, ...);

	public:
		static inline CLogger& getSingleton()
		{
			static CLogger _instance;
			return _instance;
		}
	private:
		int WriteCmdData(void* pData, int len);
	private:
		/**< .*/
		BOOL m_bOpen;
		/**< 共享内存 日志内容. */
		UTILS::CShareMemory m_smLog;
		/**< 共享内存 控制命令. */
		UTILS::CShareMemory m_smControl;
		/**< 文件名. */
		std::string m_strFile;
		/**< 写日志线程 .*/
		UTILS::CThreadBox m_tbThread;
	};
#define ULF_LOGGER CLogger::getSingleton()

#define LOG_OPEN(P1,P2,P3,P4) ULF_LOGGER.Open(P1,P2,P3,P4);
#define LOG_CLOSE() ULF_LOGGER.Close();
#define LOG(...) ULF_LOGGER.Write(__VA_ARGS__);
#define LOGEX(...) ULF_LOGGER.WriteEx(__FILE__, __LINE__, __VA_ARGS__);
}

#endif