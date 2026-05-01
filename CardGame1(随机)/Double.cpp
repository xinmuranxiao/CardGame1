#include "Double.h"

namespace gamerandom {
	Double::Double(int mode_) {
		mode = mode_;
		while (1) {
			basic = Load_GameRandomRole(address);
			if (basic.name == "error") {
				tools::out(std::string("读取失败"));
				if (tools::judge()) {
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
		chooseCard.resize(10);
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

	bool Double::passiveSkill() {//被动技能：有概率攻击翻倍
		return tools::Random(10) - basic.passiveSkill > 0 ? 1 : 0;
	}
}