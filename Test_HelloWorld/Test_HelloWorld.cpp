// Test_HelloWorld.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CProcess.h"
#include "CVOpt.h"

int main()
{
	std::cout << "Hello" << std::endl;
	CVOpt cvmanager;
	CProcess process(&cvmanager);

	getchar();
    return 0;
}

