#include "Double.h"

namespace GameRandom {
	namespace role {
		Double::Double(tools::Out& R_Out) {
			tools::File File;
			basic=File.Load_GameRandomRole(address);
		}
		RoleType Double::getBasic() {
			return basic;
		}

		float Double::getAttack() {
			return basic.attack;
		}

		float Double::getDamage() {
			return basic.damage;
		}
	}
}