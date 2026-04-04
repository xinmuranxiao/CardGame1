#include "CardGameRandom.h"

int main() {

	tools::Out Out;//设置输出流

	tools::Input Input;//设置输入流

	Out.out(std::string("any key start"));//开始界面
	Input.System(std::string("pause"));

	GameRandom::GameRandom(Out, Input);//开始游戏

	std::cout << "运行结束" << std::endl;//结束提示

	return 0;
}