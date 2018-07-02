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
		@brief �ӹ���س��ж�ȡ��־.
		*/
		void ProcPicCmdData(UTILS::CommunicatorPacket_t*);
		void ProcPicContentData(UTILS::CommunicatorPacket_t*);
		/*
		@brief д��־.
		*/
		void ThreadData(BYTE* pData, int len);
	private:
		/**< .*/
		BOOL m_bInit;
		/**< .*/
		UTILS::CShareMemory m_smLog;
		UTILS::CShareMemory m_smControl;
		/**< д��־�߳� .*/
		UTILS::CThreadBox m_tbThread;
	};
}

#endif