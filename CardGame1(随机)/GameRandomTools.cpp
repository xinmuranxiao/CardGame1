#include "GameRandomTools.h"

namespace GameRandom {
	void GameRandomTools::showRole(tools::Out& R_Out) {
		R_Out.out(std::string("1.double(达博)"));
	}

	void GameRandomTools::setPlayer(std::unique_ptr<role::Role>& player,
		tools::Out& R_Out, 
		tools::Input& R_Input) {
		while (1) {
			R_Out.out(std::string("请输入使用的角色"));
			showRole(R_Out);
			std::string judge_str_player;
			R_Input.input(judge_str_player);
			if (judge_str_player[0] == '1') {
				player = std::make_unique<role::Double>(R_Out,R_Input);
				break;
			}
			else {
				R_Out.System("cls");
				R_Out.out(std::string("输入错误,请重输"));
			}
		}
	}

	bool GameRandomTools::judge(tools::Out& R_Out, tools::Input& R_Input) {
		R_Out.out("确定输入Y/y,重选其他任意键");
		std::string judge;
		R_Input.input(judge);
		if (judge == "y" || judge == "Y") {
			return 1;
		}
		else {
			return 0;
		}
	}
}