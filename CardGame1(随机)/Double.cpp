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

	void Double::choose() {
		std::string get;
		std::vector<int>attack;
	Re:
		while (1) {
			tools::out(std::string("可选择的数为") + std::to_string(basic.ATKnum));
			for (int i = 0; i < basic.ATKnum; i++) {
				tools::out(std::string("输入第一个选择"));
				std::string in;
				tools::input(in);
				chooseCard[i] = tools::to_int(in);
				if (chooseCard[i]<0 || chooseCard[i]>basic.ATKnum) {
					tools::out(std::string("输入错误\n请重新输入"));
					goto Re;
				}
			}
			//tools::BufferClear();
			tools::out(std::string("你选择的是"));
			std::string choose="";
			for (int i = 0; i < basic.ATKnum; i++) {
				choose += std::to_string(chooseCard[i]) + " ";
			}
			tools::out(choose);
			if (judge()) {
				break;
			}
		}
	}

	bool Double::passiveSkill() {
		return Random(10) - basic.passiveSkill > 0 ? 1 : 0;
	}
}