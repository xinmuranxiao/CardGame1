#include "CardGameRandom.h"

namespace GameRandom {
	int GameRandom(tools::Out& R_Out, tools::Input& R_Input) {
		R_Out.System("cls");//清屏
		
		tools::Random Random;//生成随机数对象
		GameRandomTools tools;

		std::random_device rd;//生成随机数种子
		std::mt19937 gen(rd());//转换数
		std::uniform_int_distribution<> dis(0,9);//设置范围

		std::unique_ptr<role::Role> player = nullptr;
		while (1) {
			try {
				tools.setPlayer(player,R_Out,R_Input);
			}
			catch (...) {
				R_Out.out("know error");
				exit(1);
			}
			R_Out.out(std::string("你选择的是"));
			player->showBasic(R_Out);//查看选择
			if (tools.judge(R_Out, R_Input)) {
				break;
			}
		}

		return 1;
	}
}