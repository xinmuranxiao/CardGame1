#include "Double.h"

namespace gamerandom {
	Double::Double(int mode_) {
		mode = mode_;
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
		chooseCard.resize(10);
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

	void Double::skill() {
		if (skillopen) {
			tools::out(std::string("技能可以使用，是否使用"));
			if (judge()) {
				ATK *= basic.attack;
				skillopen = 0;
			}
		}
		if (nowActiveSkill == basic.activeSkillMP) {
			skillopen = 1;
		}
	}

	bool Double::passiveSkill() {
		return Random(10) - basic.passiveSkill > 0 ? 1 : 0;
	}
}