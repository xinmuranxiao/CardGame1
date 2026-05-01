#ifndef DOUBLE_H
#define DOUBLE_H

#include "GeneralRole.h"
#include "CGRTools.h"

namespace gamerandom {//规定在gamerandom的命名空间
	class Double : public Role {//定义Double角色
	public://公共函数
		Double() = default;//默认构造函数

		Double(int mode_);//构造读取Double信息

		float getAttack()override;//获取攻击倍率
	protected:
		bool passiveSkill();

		std::string address = std::string("Role\\Double.txt");
	};
}

#endif // !DOUBLE_H