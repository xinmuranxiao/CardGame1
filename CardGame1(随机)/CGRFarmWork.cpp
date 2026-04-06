#include "CardGameRandom.h"

namespace gamerandom {
	bool chooseRole(const std::string judge_str_player,std::unique_ptr<Role>& judge_Role) {
		if (judge_str_player[0] == '1') {
			judge_Role = std::make_unique<Double>();
			return 1;
		}
		else {
			tools::System("cls");
			tools::out(std::string("输入错误,请重输"));
			return 0;
		}
	}

	void setPlayer(std::unique_ptr<Role>& player) {
		while (1) {
			tools::out(std::string("请输入使用的角色"));
			showRole();
			std::string judge_str_player;
			tools::input(judge_str_player);
			if (chooseRole(judge_str_player, player)) {
				break;
			}
		}
	}

	void setAI(std::unique_ptr<Role>& AI) {
		while (1) {
			if (chooseRole(std::to_string(Random(1)), AI)) {
				break;
			}
		}
	}
}