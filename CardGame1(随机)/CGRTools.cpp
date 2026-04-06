#include "CGRTools.h"

namespace gamerandom {
	RoleType Load_GameRandomRole(std::string& address_) {
		std::ifstream file(address_.c_str());
		if (!file.is_open()) {
			RoleType error;
			error.name = std::string("error");
			return error;
		}
		RoleType load_role;
		file >> load_role.CID >> load_role.name >> load_role.HP >>
			load_role.MP >> load_role.activeSkillMP >>
			load_role.passiveSkill >> load_role.attack >>
			load_role.damage >> load_role.dicenum >>
			load_role.ATKnum >> load_role.DMGnum;
		return load_role;
	}

	int Random(int n) {
		std::random_device rd;//生成随机数种子
		std::mt19937 gen(rd());//转换数
		std::uniform_int_distribution<> dis(0, n);//设置范围
		return dis(gen);
	}

	void showRole() {
		tools::out(std::string("1.double(达博)"));
	}

	bool judge() {
		tools::out("确定输入Y/y,重选其他任意键");
		std::string judge;
		tools::input(judge);
		if (judge == "y" || judge == "Y") {
			return 1;
		}
		else {
			return 0;
		}
	}
}