#ifndef GENERALROLE_H
#define GENERALROLE_H

#include "RandomCommon.h"

#include "Tools.h"

namespace GameRandom {

	namespace role {
		class Role {
		public:
			virtual float getAttack();//获得攻击倍率

			virtual float getDamage();//获得防御倍率

			void changeHP(int changeHP);//修改血量

			int getHP();//获得血量倍率

			void showBasic(tools::Out& R_Out);//查看基础信息

			virtual void pushRandom();//存储抽取的数值
		protected:
			RoleType basic;//存储数据

			bool nowActiveSkill = 0;
			bool nowPassiveSkill = 0;

			bool skillopen=0;
		};
	}
}

#endif // !GENERALROLE_H