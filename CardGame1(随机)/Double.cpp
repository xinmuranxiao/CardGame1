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
	}

	int Double::skill() {
		ATK *= basic.attack;
		if (nowActiveSkill >= basic.activeSkillMP) {
			tools::out(std::string("主动技能已准备好，是否使用主动技能，使用后攻击翻倍"));
			if (mode == 1) {//主动技能：攻击翻倍
				if (player_skillchoose()) {
					ATK *= 2;
					nowActiveSkill = 0;
				}
			}
			else if (mode == 2) {//AI主动技能：有概率攻击翻倍
			}
			if (passiveSkill()) {
				ATK *= 2;
			}
		}
		if(passiveSkill()) {
			tools::out(std::string("被动技能发动，攻击翻倍\n最终伤害为")+std::to_string(ATK));
			return ATK * 4;
		}
		else {
			tools::out(std::string("被动技能未发动，攻击倍率不变\n最终伤害为")+std::to_string(ATK));
			return ATK;
		}
	}


	bool Double::player_skillchoose() {
		tools::out(std::string("输入Y/y使用"));
		if (tools::judge()) {
			tools::out(std::string("主动技能发动，攻击翻倍"));
			return 1;
		}
		else {
			tools::out(std::string("主动技能未发动，攻击倍率不变"));
			return 0;
		}
	}

	bool Double::passiveSkill() {//被动技能：有概率攻击翻倍
		return tools::Random(10) - basic.passiveSkill > 0 ? 1 : 0;
	}
}