#include "Tools.h"

namespace tools {
	void Tools::out(std::string str) {
		std::cout << str << std::endl;
	}

	void Tools::input(std::string& str) {
		std::cin >> str;
	}

	int Tools::to_int(const std::string& str) {
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

	double Tools::to_float(const std::string& str) {
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

	int Tools::random(std::uniform_int_distribution<>& dis, std::mt19937& gen) {
		return dis(gen);
	}
	
	GameRandom::RoleType File::Load_GameRandomRole(std::string& address_) {
		std::ifstream file;
		GameRandom::RoleType load_role;
		file >> load_role.CID >> load_role.name >> load_role.HP >>
			load_role.MP >> load_role.SkillMP >> load_role.attack >>
			load_role.damage >> load_role.dicenum >> load_role.ATKnum >>
			load_role.DMGnum;
		return load_role;
	}
}