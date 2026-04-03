#include "Double.h"

namespace GameRandom {
	namespace role {
		Double::Double(tools::Out& R_Out, tools::Input& R_Input) {
			while (1) {
				tools::File File;
				basic = File.Load_GameRandomRole(address);
				if (basic.name == "error") {
					R_Out.out(std::string("读取失败"));
					R_Out.out("确定输入Y/y,重选其他任意键");
					std::string judge;
					R_Input.input(judge);
					if (judge == "y" || judge == "Y") {
						continue;
					}
					else {
						throw std::ios_base::failure(address+std::string(":read file error"));
					}
				}
				else {
					break;
				}
			}
		}
		void Double::showBasic(tools::Out& R_Out) {
			R_Out.out(std::string("姓名:") + basic.name);//输出性别
			R_Out.out(std::string("HP:") + std::to_string(basic.HP));
			R_Out.out(std::string("MP:") + std::to_string(basic.MP));
			R_Out.out(std::string("总共骰子:") + std::to_string(basic.dicenum));
			R_Out.out(std::string("攻击骰子:") + std::to_string(basic.ATKnum));
			R_Out.out(std::string("防御骰子:") + std::to_string(basic.DMGnum));
		}

		float Double::getAttack() {
			return basic.attack;
		}

		float Double::getDamage() {
			return basic.damage;
		}
	}
}