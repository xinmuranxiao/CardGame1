#include "GameRandomTools.h"

namespace GameRandom {
	void GameRandomTools::showRole(tools::Out& R_Out) {
		R_Out.out(std::string("1.double(达博)"));
	}

	void GameRandomTools::setPlayer(std::unique_ptr<role::Role>& player,
		tools::Out& R_Out, 
		tools::Input& R_Input) {
		R_Out.out(std::string("请输入使用的角色"));

		showRole(R_Out);
		while (1) {
			std::string judge_str_player;
			R_Input.input(judge_str_player);
			if (judge_str_player[0] == '1') {
				player = std::make_unique<role::Double>(R_Out);
				break;
			}
			else {
				R_Out.out(std::string("输入错误,请重输"));
			}
		}
	}
}