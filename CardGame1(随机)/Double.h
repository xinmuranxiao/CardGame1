#ifndef DOUBLE_H
#define DOUBLE_H

#include "GeneralRole.h"
#include "CGRTools.h"

namespace gamerandom {//规定在gamerandom的命名空间
	class Double : public Role {//定义Double角色
	public://公共函数
		Double() = default;//默认构造函数

		Double(int mode_);//构造读取Double信息

		int skill() override;//技能的使用

	protected:
		bool passiveSkill();

		bool player_skillchoose();//玩家主动技能选择

		std::string address = std::string("Role\\Double.txt");
	};
}

#endif // !DOUBLE_H