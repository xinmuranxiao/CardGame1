#ifndef GAMERANDOMCOMMON_H
#define GAMERANDOMCOMMON_H

#include "Role.h"
#include "Tools.h"

namespace GameRandom {
	class GameRandomTools {
	public:
		void showRole(tools::Out& R_Out);

		void setPlayer(std::unique_ptr<role::Role>& player,
			tools::Out& R_Out,
			tools::Input& R_Input);
	};
}

#endif // RANDOMCOMMON_H