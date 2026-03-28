#ifndef GENERALROLE_H
#define GENERALROLE_H

#include "Common.h"

namespace {
	class Role {
	public:
		Role();

		virtual long long getAttack()=0;  

	protected:
		int attack;
		int defense;
	};
}

#endif // !GENERALROLE_H
