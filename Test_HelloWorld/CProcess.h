#pragma once
#include <thread>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <functional>

typedef std::function<void(int _i, const char * _data, size_t _len)> OnConvert;
typedef void(*OnConvert2)(int _i, const char * _data, size_t _len);

class CVOpt;
class CProcess
{
public:
	CProcess(CVOpt* _p_cv);
	~CProcess();

	void Work();
	static void DoCallBack(int _i, const char* _data, size_t _len);

private:
	std::thread	th_work;
	CVOpt* cv;
};


static void DoCallBack2(int _i, const char* _data, size_t _len);

