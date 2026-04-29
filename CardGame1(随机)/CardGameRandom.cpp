#include "CardGameRandom.h"

namespace gamerandom {
	int GameRandom() {
		tools::System("cls");//清屏

		std::unique_ptr<Role> player = nullptr;//存储用户指针
		while (1) {//选择
			try {
				setPlayer(player);//选择用户角色
			}
			catch (const std::ios_base::failure& e) {//捕获异常
				tools::out(e.what());
				exit(2);//退出为2
			}
			catch (...) {//未知报错
				tools::out("know error");
				exit(1);
			}
			tools::out(std::string("你选择的是"));//打印“你选择的是”
			player->showBasic();//查看选择
			if (judge()) {
				break;
			}
			tools::System("cls");//清屏
		}

		std::unique_ptr<Role> AI = nullptr;//存储AI指针
		tools::out(std::string("AI选择的是："));
		try {
			setAI(AI);//选择AI角色
		}
		catch (const std::ios_base::failure& e) {
			tools::out(e.what());
			exit(2);
		}
		catch (...) {
			tools::out("know error");
			exit(1);
		}
		AI->showBasic();

		tools::out(std::string("游戏开始"));
		tools::System(std::string("pause"));//按键开始

		while (1) {
			tools::System("cls");
			player->pushRandom();
			player->showDCM();
			player->choose(1);

			if (AI->getHP() < 0 || player->getHP() < 0) {
				break;
			}
			else if(judge()) {
				break;
			}
		}

		return (player->getHP() - AI->getHP())/5;//总的硬币变化为对应血量
	}
}