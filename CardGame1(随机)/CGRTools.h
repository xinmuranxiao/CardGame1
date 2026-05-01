#ifndef GAMERANDOMCOMMON_H
#define GAMERANDOMCOMMON_H

#include "Tools.h"
#include "GeneralRole.h"

namespace gamerandom {
	RoleType Load_GameRandomRole(std::string& address_);//从文件加载角色数据

	void setPlayer(std::unique_ptr<Role>& player);//设置玩家角色

	void setAI(std::unique_ptr<Role>& AI);//设置AI角色

	void showRole();//显示角色信息

	bool chooseRole(const std::string judge_str_player, std::unique_ptr<Role>& judge_Role);//选择角色
}

#endif // RANDOMCOMMON_H