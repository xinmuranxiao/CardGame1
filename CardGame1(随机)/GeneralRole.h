#ifndef GENERALROLE_H
#define GENERALROLE_H

#include "Common.h"

#include ""


using PlayerGameR = std::pair<std::pair<uint64_t, std::string>, std::pair<int, int>>;


namespace {
	class Role {
	public:
		virtual long long getAttack() = 0;

	protected:
		PlayerGameR basic;
	};
}

#endif // !GENERALROLE_H
