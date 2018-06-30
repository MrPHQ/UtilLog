#ifndef __UTIL_LOG_SERVER__
#define __UTIL_LOG_SERVER__

namespace UTIL_LOG
{
	/**
	@brief ��־�����.
	*/
	class UTIL_LOG_CPPAPI CLogServer
	{
	public:
		CLogServer();
		~CLogServer();

		/**
		@brief ����.
		*/
		int Start();
		/**
		@brief ֹͣ.
		*/
		void Stop();

	private:
		/*
		@brief ��ȡ��־.
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