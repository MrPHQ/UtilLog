#ifndef __UTILLOG_LOGGER__
#define __UTILLOG_LOGGER__

namespace UTIL_LOG
{
	/**
	\brief
		��־�ļ���¼ͷ��Ϣ.
	*/
	enum LOG_HEAD {
		/**< дʱ�� */
		LOG_HEAD_TIME = 0x01,
		/**< д������ */
		LOG_HEAD_PROC_NAME = 0x02,
		/**< д����ID */
		LOG_HEAD_PROC_ID = 0x04,
		/**< д�߳�ID */
		LOG_HEAD_THREAD_ID = 0x08,
		/**< д�ļ��� */
		LOG_HEAD_FILE_NAME = 0x10,
		/**< д�к� */
		LOG_HEAD_FILE_LINE = 0x20,
	};

	/**
	@brief ��־�ͻ���.
	*/
	class UTIL_LOG_CPPAPI CLogger
	{
	public:
		CLogger();
		~CLogger();
		/**
		\brief
			���ļ�
			ע��: ��־ָ������־�ļ�������,��ᴴ��,����Ѿ�����,��򿪺�ֱ�Ӷ�λ���ļ�ĩβ.
		\param nHead
			��־�ļ���¼ͷ��Ϣ. �μ�LOG_HEAD
		\param file
			��־�ļ�(�ļ���).
		\param uiDays
			�洢����
		\param uiPerFileSize
			ÿ����־�ļ��������. �ֽ�.
		\return
			Error.h
		*/
		int Open(DWORD nHead, const char* file, unsigned int uiDays, unsigned int uiPerFileSize);
		/**
		\brief
			�ر��ļ�
		*/
		void Close();
		/**
		\brief д����־.
			ע������ַ������� [1024*256]
		*/
		void Write(const char* pFormat, ...);
		/**
		\brief
			д����־.
		\param file
			��־λ�������ļ�.
		\param line
			��־����λ���ļ��к�.
		*/
		void WriteEx(const char* file, int line, const char* pFormat, ...);

	private:
		int WriteCmdData(void* pData, int len);
	private:
		/**< .*/
		BOOL m_bOpen;
		/**< �����ڴ� ��־����. */
		UTILS::CShareMemory m_smLog;
		/**< �����ڴ� ��������. */
		UTILS::CShareMemory m_smControl;
		/**< �ļ���. */
		std::string m_strFile;
		/**< д��־�߳� .*/
		UTILS::CThreadBox m_tbThread;
	};
}

#endif