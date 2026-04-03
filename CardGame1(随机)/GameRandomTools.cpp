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
			if (chooseRole(judge_str_player,
				R_Out, R_Input, player)) {
				break;
			}
		}
	}

	void GameRandomTools::setAI(std::unique_ptr<role::Role>& AI,
		tools::Out& R_Out,tools::Input& R_Input) {
		std::random_device rd;//生成随机数种子
		std::mt19937 gen(rd());//转换数
		std::uniform_int_distribution<> dis(0, 1);//设置范围
		while (1) {
			if (chooseRole(std::to_string(dis(gen)), R_Out, R_Input, AI)) {
				break;
			}
		}
	}

	bool GameRandomTools::chooseRole(const std::string judge_str_player,
		tools::Out& R_Out, tools::Input& R_Input,
		std::unique_ptr<role::Role>& judge_Role) {
		if (judge_str_player[0] == '1') {
			judge_Role = std::make_unique<role::Double>(R_Out, R_Input);
			return 1;
		}
		else {
			R_Out.System("cls");
			R_Out.out(std::string("输入错误,请重输"));
			return 0;
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