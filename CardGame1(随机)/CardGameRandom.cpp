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
			catch (const std::ios_base::failure& e) {
				R_Out.out(e.what());
				exit(2);
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
			R_Out.System("cls");
		}

		std::unique_ptr<role::Role> AI = nullptr;
		R_Out.out(std::string("AI选择的是："));
		try {
			tools.setAI(AI, R_Out, R_Input);
		}
		catch (const std::ios_base::failure& e) {
			R_Out.out(e.what());
			exit(2);
		}
		catch (...) {
			R_Out.out("know error");
			exit(1);
		}
		AI->showBasic(R_Out);

		R_Out.out(std::string("游戏开始"));
		R_Input.System(std::string("pause"));

		while (1) {

			R_Out.System("cls");
			if (AI->getHP() < 0 || player->getHP() < 0) {
				break;
			}
			else if(tools.judge(R_Out,R_Input)) {
				break;
			}
		}

		return (player->getHP() - AI->getHP())/5;//总的硬币变化为对应血量
	}
}