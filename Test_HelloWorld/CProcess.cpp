#include "stdafx.h"
#include "CProcess.h"
#include "CVOpt.h"

CProcess::CProcess(CVOpt* _p_cv)
	:cv(_p_cv)
{
	th_work = std::thread(std::bind(&CProcess::Work, this));
}


CProcess::~CProcess()
{
}

void CProcess::Work()
{
	auto print_time = []()->void {
		std::time_t t = std::time(nullptr);
		std::tm tm = *std::localtime(&t);
		std::cout << "ru_RU: " << std::put_time(&tm, "%c") << '\n';
	};

	int i = 0;
	while (++i > 0)
	{
		print_time();
		cv->do_cv(&CProcess::DoCallBack);
		std::this_thread::sleep_for(std::chrono::seconds(30));
	}
}

void CProcess::DoCallBack(int _i, const char * _data, size_t _len)
{
	std::cout << "DoCallBack i=" << _i
		<< " data=" << _data
		<< " _len=" << _len
		<< std::endl;
}

void DoCallBack2(int _i, const char * _data, size_t _len)
{
	std::cout << "DoCallBack2 i=" << _i
		<< " data=" << _data
		<< " _len=" << _len
		<< std::endl;
}
