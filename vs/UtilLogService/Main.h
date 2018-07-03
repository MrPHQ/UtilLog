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
	@brief 主线程循环.
	\param hExit
		退出事件.
	*/
	void Run(HANDLE hExit);
private:
	BOOL m_bStartUp;
	UTIL_LOG::CLogServer m_logServer;
};

