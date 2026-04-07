#include "Double.h"

namespace gamerandom {
	Double::Double() {
		while (1) {
			basic = Load_GameRandomRole(address);
			if (basic.name == "error") {
				tools::out(std::string("读取失败"));
				if (judge()) {
					continue;
				}
				else {
					throw std::ios_base::failure(address + std::string(":read file error"));
				}
			}
			else {
				break;
			}
		}
		DCM.resize(basic.dicenum);
	}

	void Double::pushRandom() {
		for (int i = 0; i < basic.dicenum; i++) {
			DCM[i] = Random(9) + 1;
		}
	}

	float Double::getAttack() {
		float ATK = basic.attack;
		if (nowActiveSkill) {
			nowActiveSkill = 0;
			ATK *= 2;
		}
		if (passiveSkill()) {
			ATK *= 2;
		}
		return ATK;
	}

	void Double::showDCM() {
		std::string str = std::string("抽取的数值为:\n");
		for (int i = 0; i < basic.dicenum; i++) {
			str += (std::to_string(i+1)) + " ";
		}
		str += "\n";
		for (int i = 0; i < basic.dicenum; i++) {
			str += std::to_string(DCM[i]) + " ";
		}
		tools::out(str);
	}

	void Double::choose() {
		std::string get;
		std::vector<int>attack;
		while (1) {
			tools::getLine(get);//获取选择的
			int j = 0,p=0;//统计输入的数字,以及偏移量
			for (int i = 0; i < get.size(); i++) {
				if (get[i] == ' ') {
					attack.push_back(tools::to_int(get.substr(i - p - 1, i - 1)));
					j++;
					p = 0;
				}
				else {
					p++;
				}
			}
			if (!(0 <= j && j + 1 <= basic.ATKnum)) {
				tools::out(std::string("输入错误，请重新输入"));
				continue;
			}

			tools::out(std::string("你选择的是"));
			for (auto i : attack) {
				tools::out(std::to_string(i)+" ");
			}
			if (judge()) {
				break;
			}
		}
	}

	bool Double::passiveSkill() {
		return Random(10) - basic.passiveSkill > 0 ? 1 : 0;
	}
}