#include "CGRTools.h"

namespace gamerandom {
	RoleType Load_GameRandomRole(std::string& address_) {//从文件中读取角色信息
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

	void showRole() {//显示角色信息
		tools::out(std::string("1.double(达博)"));
	}
}