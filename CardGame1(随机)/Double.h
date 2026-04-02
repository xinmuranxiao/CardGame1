#ifndef DOUBLE_H
#define DOUBLE_H

#include "GeneralRole.h"

#include "Tools.h"

namespace GameRandom {
	namespace role {
		class Double :public Role {
		public:
			Double(tools::Out& R_Out, tools::Input& R_Input);

			void showBasic(tools::Out& R_Out);

			float getAttack()override;
			float getDamage()override;
		protected:
			int skill = 4;//用于判定是否被触发

			std::vector<int>ATK;
			std::vector<int>DMG;

			std::string address=std::string("Role\\Double.txt");
		};
	}
}

#endif // !DOUBLE_H