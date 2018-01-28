#include "stdafx.h"
#include "CVOpt.h"
#include "CProcess.h"
#include <sstream>
#include <iostream>
#include <functional>

CVOpt::CVOpt()
{
	
}


CVOpt::~CVOpt()
{
}

void CVOpt::do_cv(void* _cb)
{
	th_work = std::thread(std::bind(&CVOpt::cv_thread, this, _cb));
}

void CVOpt::cv_thread(void*  _cb)
{

	int i = 100;
	while (++i)
	{
		if (i % 3 == 0)
		{
			on_cv_over(_cb, i);
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void CVOpt::on_cv_over(void*  _cb, int _val)
{
	OnConvert2* pFn = (OnConvert2*)_cb;

	if (pFn)
	{
		std::stringstream ss;
		ss << "Test Git Get Data " << _val;

		((OnConvert2)_cb)(_val, ss.str().c_str(), ss.str().length());
		//(*pFn)(_val, ss.str().c_str(), ss.str().length());
	}
}
