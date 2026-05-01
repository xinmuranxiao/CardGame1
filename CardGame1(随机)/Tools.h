#ifndef TOOLS_H
#define TOOLS_H

#include "RandomCommon.h"

namespace tools {
	void out(std::string str);

	void input(std::string& str);

	int to_int(const std::string& str);//string to int

	double to_float(const std::string& str);//string to float

	void System(const std::string& str);//系统控制台
	
	void BufferClear();//清理缓存区
}

#endif // !TOOLS_H