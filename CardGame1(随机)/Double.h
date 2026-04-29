#ifndef DOUBLE_H
#define DOUBLE_H

#include "GeneralRole.h"
#include "CGRTools.h"

namespace gamerandom {//规定在gamerandom的命名空间
	class Double : public Role {//定义Double角色
	public://公共函数
		Double();//构造读取Double信息

		float getAttack()override;//获取攻击倍率

		void showBasic();//输出基础的信息（名称和HP,MP,攻击骰子，防御骰子）

		void pushRandom()override;

		void showDCM()override;//输出抽取的数值

		void choose(int mode) override;//选择
	protected:
		bool passiveSkill();

		std::vector<int> DCM;//存储抽取的数值

		std::string address = std::string("Role\\Double.txt");
	};
}

#endif // !DOUBLE_H