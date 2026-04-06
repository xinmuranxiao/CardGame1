#include "Double.h"

namespace gamerandom {
	Double::Double() {
		while (1) {
			basic = Load_GameRandomRole(address);
			if (basic.name == "error") {
				tools::out(std::string("读取失败"));
				tools::out("确定输入Y/y,重选其他任意键");
				std::string judge;
				tools::input(judge);
				if (judge == "y" || judge == "Y") {
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
		DCM.reserve(basic.dicenum);
	}

	void Double::pushRandom() {
		for (int i = 0; i < DCM.size(); i++) {
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

	bool Double::passiveSkill() {
		return Random(10) - basic.passiveSkill > 0 ? 1 : 0;
	}
}