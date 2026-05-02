#include"GeneralRole.h"

namespace gamerandom {
	void Role::changeHP(int changeHP) {
		basic.HP += changeHP;
	}

	int Role::getHP() {
		return basic.HP;
	}

	float Role::getAttack() {
		return basic.attack;
	}

	float Role::getDamage() {
		return basic.damage;
	}

	void Role::showBasic() {
		tools::out(std::string("姓名:") + basic.name);//输出性别
		tools::out(std::string("HP:") + std::to_string(basic.HP));
		tools::out(std::string("MP:") + std::to_string(basic.MP));
		tools::out(std::string("总共骰子:") + std::to_string(basic.dicenum));
		tools::out(std::string("攻击骰子:") + std::to_string(basic.ATKnum));
		tools::out(std::string("防御骰子:") + std::to_string(basic.DMGnum));
	}

	void Role::choose() {
		std::string get;
		std::vector<int>attack;
		pushRandom();
		showDCM();
		if (mode == 1) {//mode==1时人来操作
			playearATKchoose();
		}
		else if (mode == 2) {//mode==2时AI操作

		}
	}

	void Role::playearATKchoose() {
		while (1) {
		Rec://标签，输入错误时跳转到这里
			tools::out(std::string("可选择的数为") + std::to_string(basic.ATKnum));
			for (int i = 0; i < basic.ATKnum; i++) {
			Reic://标签，输入错误时跳转到这里	
				tools::out(std::string("输入第") + std::to_string(i + 1) + std::string("个选择"));
				std::string in;
				tools::input(in);
				if(tools::to_int(in)<0||tools::to_int(in)>basic.dicenum)
					goto Reic;
				chooseCard.insert( tools::to_int(in) - 1);
			}
			//tools::BufferClear();
			if (chooseCard.size() < basic.ATKnum) {
				tools::out(std::string("输入错误，已选择的数为") + std::to_string(chooseCard.size()) + std::string("个，少输入了"));
				goto Rec;
			}
			tools::out(std::string("选择的是"));
			std::string choose = "";
			for (auto i = chooseCard.begin(); i != chooseCard.end(); i++) {
				choose += std::to_string(*i + 1) + " ";
				ATK += DCM[*i];
			}
			tools::out(choose);
			if (tools::judge()) {
				tools::out(std::string("本轮选择总和点数为") + std::to_string(ATK));
				break;
			}
		}
	}

	void Role::pushRandom() {
		for (int i = 0; i < basic.dicenum; i++) {
			DCM[i] = tools::Random(9) + 1;
		}
	}

	void Role::showDCM() {
		std::string str = std::string("抽取的数值为:\n");
		for (int i = 0; i < basic.dicenum; i++) {
			str += (std::to_string(i + 1)) + " ";
		}
		str += "\n";
		for (int i = 0; i < basic.dicenum; i++) {
			str += std::to_string(DCM[i]) + " ";
		}
		tools::out(str);
	}

	void Role::skill() {
		if (skillopen) {
			tools::out(std::string("技能可以使用，是否使用"));
			if (tools::judge()) {
				ATK *= basic.attack;
				skillopen = 0;
			}
		}
		if (nowActiveSkill) {
			skillopen = 1;
		}
	}
}