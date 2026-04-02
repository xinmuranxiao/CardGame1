#ifndef GENERALROLE_H
#define GENERALROLE_H

#include "RandomCommon.h"

#include "Tools.h"

namespace GameRandom {

	namespace role {
		class Role {
		public:
			virtual float getAttack() = 0;

			virtual float getDamage() = 0;

			virtual void showBasic(tools::Out& R_Out) = 0;
		protected:
			RoleType basic;
		};
	}
}

#endif // !GENERALROLE_H