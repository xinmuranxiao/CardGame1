#ifndef TOOLS_H
#define TOOLS_H

#include "RandomCommon.h"

namespace tools {
	void out(std::string str);

	void input(std::string& str);

	int to_int(const std::string& str);//string to int

	double to_float(const std::string& str);//string to float

	void System(const std::string& str);//系统控制台
	
	bool judge();//判断输入是否为y或n

	int Random(int n);//随机数生成器，生成1~n的随机数
}

#endif // !TOOLS_H