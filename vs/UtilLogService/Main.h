#pragma once
class CMain
{
private:
	CMain();
	~CMain();
public:
	static CMain& GetInstance();

	int Start();
	void Stop();
	/*
	@brief ���߳�ѭ��.
	\param hExit
		�˳��¼�.
	*/
	void Run(HANDLE hExit);
private:
	BOOL m_bStartUp;
	UTIL_LOG::CLogServer m_logServer;
};

