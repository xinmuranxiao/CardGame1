#ifndef RANDOMCOMMON_H
#define RANDOMCOMMON_H

#include "Common.h"

namespace GameRandom {
	using RoleType = struct {
		uint64_t CID;//角色ID

		std::string name;//名字

		int HP;//血量
		int MP;//蓝值

		
		int activeSkillMP;//主动技能蓝量
		int passiveSkill;//被动技能

		float attack;//攻击倍率
		float damage;//防御倍率

		int dicenum;//总量
		int ATKnum;//攻击牌
		int DMGnum;//防御牌
	};
}

#endif // !RANDOMCOMMON_H
