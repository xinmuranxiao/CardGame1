#include "CardGameRandom.h"

namespace GameRandom {
	void showRole(tools::Out& R_Out) {
		R_Out.out(std::string("1.double(达博)"));
	}

	int GameRandom(tools::Out& R_Out, tools::Input& R_Input) {

		system("cls");

		tools::Random Random;

		std::random_device rd;//生成随机数种子
		std::mt19937 gen(rd());//转换数
		std::uniform_int_distribution<> dis(0,9);//设置范围

		R_Out.out(std::string("请输入使用的角色"));

		showRole(R_Out);

		std::string judge_str_player;
		R_Input.input(judge_str_player);
		role::Role* player=NULL;
		if (judge_str_player[0] == '1') {
			player = new role::Double(R_Out);
		}
		return 1;
	}
}