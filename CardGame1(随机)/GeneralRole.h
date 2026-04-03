#ifndef GENERALROLE_H
#define GENERALROLE_H

#include "RandomCommon.h"

#include "Tools.h"

namespace GameRandom {

	namespace role {
		class Role {
		public:
			virtual float getAttack() = 0;//获得攻击倍率

			virtual float getDamage() = 0;//获得防御倍率

			void changeHP(int changeHP);//修改血量

			int getHP();//获得血量倍率

			virtual void showBasic(tools::Out& R_Out) = 0;//查看基础信息
		protected:
			RoleType basic;
		};
	}
}

#endif // !GENERALROLE_H