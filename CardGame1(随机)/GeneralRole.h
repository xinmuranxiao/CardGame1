#ifndef GENERALROLE_H
#define GENERALROLE_H

#include "Common.h"
#include "Tools.h"

namespace gamerandom {
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
		int ATKnum;//攻击量
		int DMGnum;//防御量
	};

	class Role {
	public:
		virtual float getAttack();//获得攻击倍率

		virtual float getDamage();//获得防御倍率

		void changeHP(int changeHP);//修改血量

		int getHP();//获得血量倍率

		void showBasic();//查看基础信息

		virtual void pushRandom() = 0;//存储抽取的数值

		virtual void showDCM() = 0;//查看抽取的卡牌数

		virtual void choose() = 0;

		bool judge();

		virtual ~Role() = default;
	protected:
		RoleType basic;//存储数据

		bool nowActiveSkill = 0;
		bool nowPassiveSkill = 0;

		bool skillopen = 0;

		int ATK = 0;
		int DMG = 0;
	};
}

#endif // !GENERALROLE_H