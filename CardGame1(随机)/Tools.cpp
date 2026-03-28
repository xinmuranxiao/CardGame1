#include "Tools.h"

namespace tools {
	void Tools::out(std::string str) {
		std::cout << str << std::endl;
	}

	void Tools::input(std::string& str) {
		std::cin >> str;
	}
}