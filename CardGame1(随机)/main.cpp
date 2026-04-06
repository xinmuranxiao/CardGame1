#include "CardGameRandom.h"

int main() {
	tools::out(std::string("any key start"));//开始界面
	tools::System(std::string("pause"));

	gamerandom::GameRandom();//开始游戏

	std::cout << "运行结束" << std::endl;//结束提示

	return 0;
}