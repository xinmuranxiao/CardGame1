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
}