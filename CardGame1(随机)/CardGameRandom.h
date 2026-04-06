#ifndef CARDGAMERANDOM_H
#define CARDGAMERANDOM_H

#include "Role.h"
#include "CGRTools.h"

namespace gamerandom {
	bool chooseRole(const std::string judge_str_player, std::unique_ptr<Role>& judge_Role);

	void setPlayer(std::unique_ptr<Role>& player);

	void setAI(std::unique_ptr<Role>& AI);

	int GameRandom();
}

#endif // !CARDGAMERANDOM_H