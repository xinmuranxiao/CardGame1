#include"GeneralRole.h"

namespace GameRandom {
	namespace role {
		void Role::changeHP(int changeHP) {
			basic.HP += changeHP;
		}

		int Role::getHP() {
			return basic.HP;
		}

		float Role::getAttack() {
			return basic.attack;
		}

		float Role::getDamage() {
			return basic.damage;
		}
	}
}