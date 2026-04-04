#ifndef GAMERANDOMCOMMON_H
#define GAMERANDOMCOMMON_H

#include "Role.h"
#include "Tools.h"

namespace GameRandom {
	class GameRandomTools {
	public:
		void showRole(tools::Out& R_Out);

		void setPlayer(std::unique_ptr<role::Role>& player,
			tools::Out& R_Out,tools::Input& R_Input);

		void setAI(std::unique_ptr<role::Role>& AI,
			tools::Out& R_Out,
			tools::Input& R_Input);

		bool chooseRole(const std::string judge_str_player,
			tools::Out& R_Out, tools::Input& R_Input,
			std::unique_ptr<role::Role>& judge_Role);

		bool judge(tools::Out& R_Out, tools::Input& R_Input);
	};


}

#endif // RANDOMCOMMON_H