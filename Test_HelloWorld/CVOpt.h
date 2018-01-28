#pragma once
#include <thread>
#include "CProcess.h"

class CVOpt
{
public:
	CVOpt();
	~CVOpt();

	void do_cv(void* _cb);
	void cv_thread(void* _cb);
	static void on_cv_over(void* _cb, int _val);

private:
	std::thread	th_work;
};

