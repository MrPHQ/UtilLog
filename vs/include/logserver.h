#ifndef __UTIL_LOG_SERVER__
#define __UTIL_LOG_SERVER__

namespace UTIL_LOG
{
	/**
	@brief 日志服务端.
	*/
	class UTIL_LOG_CPPAPI CLogServer
	{
	public:
		CLogServer();
		~CLogServer();

		/**
		@brief 启动.
		*/
		int Start();
		/**
		@brief 停止.
		*/
		void Stop();

	private:
		/*
		@brief 从共享回车中读取日志.
		*/
		void ProcPicCmdData(UTILS::CommunicatorPacket_t*);
		void ProcPicContentData(UTILS::CommunicatorPacket_t*);
		/*
		@brief 写日志.
		*/
		void ThreadData(BYTE* pData, int len);
	private:
		/**< .*/
		BOOL m_bInit;
		/**< .*/
		UTILS::CShareMemory m_smLog;
		UTILS::CShareMemory m_smControl;
		/**< 写日志线程 .*/
		UTILS::CThreadBox m_tbThread;
	};
}

#endif