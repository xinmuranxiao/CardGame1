#include "Tools.h"

namespace tools {
	void out(std::string str) {
		std::cout << str << std::endl;
	}

	void input(std::string& str) {
		std::cin >> str;
	}

	void getLine(std::string& str) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, str);
	}

	int to_int(const std::string& str) {
		if (str.empty()) {
			throw std::invalid_argument(std::string("str empty!"));
		}
		int num = 0, POM = 1, i = 0;
		if (str[0] == '-') {
			POM = -1;
			i = 1;
		}
		for(i; i < str.size(); i++) {
			num = num * 10 + (str[i] - '0');
		}
		return POM*num;
	}

	double to_float(const std::string& str) {
		if (str.empty()) {
			throw std::invalid_argument(std::string("str empty!"));
		}
		double num = 0;
		int POM = 1, i = 0, place = 1;
		bool judge = 1;//整数与小数
		if (str[0] == '-') {
			POM = -1;
			i = 1;
		}
		for (i; i < str.size(); i++) {
			if (str[i] == '.') {
				judge = 0;
			}
			else if (judge) {
				num = num * 10 + (str[i] - '0');
			}
			else {
				num += (str[i] - '0') * pow(0.1, place);
				place++;
			}
		}
		return POM*num;
	}
	
	void System(const std::string& str) {
		system(str.c_str());
	}
}