#ifndef DOUBLE_H
#define DOUBLE_H

#include "GeneralRole.h"

#include "Tools.h"

namespace GameRandom {//规定在GameRandom的命名空间
	namespace role {//规定角色空间
		class Double :public Role {//定义Double角色
		public://公共函数
			Double(tools::Out& R_Out, tools::Input& R_Input);//构造读取Double信息

			float getAttack()override;//获取

			void showBasic(tools::Out& R_Out);//输出基础的信息（名称和HP,MP,攻击骰子，防御骰子）

			void pushRandom()override;
		protected:
			int getRandom();

			std::vector<int>DCM;

			std::string address=std::string("Role\\Double.txt");
		};
	}
}

#endif // !DOUBLE_H