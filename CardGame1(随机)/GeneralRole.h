#ifndef GENERALROLE_H
#define GENERALROLE_H

#include "Common.h"

namespace {
	class Role {
	public:
		virtual long long getAttack()=0;  

	protected:
		int attack = 1;
		int defense = 1;
	};
}

#endif // !GENERALROLE_H
