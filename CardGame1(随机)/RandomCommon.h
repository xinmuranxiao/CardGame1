#ifndef RANDOMCOMMON_H
#define RANDOMCOMMON_H


#include "Common.h"

namespace GameRandom {
	using RoleType = struct {
		uint64_t CID;//角色ID

		std::string name;//名字

		int HP;//血量
		int MP;//蓝值

		int SkillMP;//技能蓝量

		float attack;//攻击倍率
		float damage;//防御倍率

		int dicenum;
		int ATKnum;
		int DMGnum;
	};
}

#endif // !RANDOMCOMMON_H
