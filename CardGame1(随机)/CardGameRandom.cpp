#include "CardGameRandom.h"

namespace gamerandom {
	int GameRandom() {
		tools::System("cls");//清屏

		std::unique_ptr<Role> player = nullptr;
		while (1) {
			try {
				setPlayer(player);
			}
			catch (const std::ios_base::failure& e) {
				tools::out(e.what());
				exit(2);
			}
			catch (...) {
				tools::out("know error");
				exit(1);
			}
			tools::out(std::string("你选择的是"));
			player->showBasic();//查看选择
			if (judge()) {
				break;
			}
			tools::System("cls");
		}

		std::unique_ptr<Role> AI = nullptr;
		tools::out(std::string("AI选择的是："));
		try {
			setAI(AI);
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
		tools::System(std::string("pause"));

		while (1) {

			tools::System("cls");
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