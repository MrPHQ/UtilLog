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
		@brief 读取日志.
		*/
		void ProcPicData(UTILS::CommunicatorPacket_t*);
	private:
		/**< .*/
		BOOL m_bInit;
		/**< .*/
		UTILS::CShareMemory m_smLog;
		UTILS::CShareMemory m_smControl;
	};
}

#endif