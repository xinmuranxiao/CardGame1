#ifndef TOOLS_H
#define TOOLS_H

#include "Common.h"
#include "RandomCommon.h"

namespace tools {
	class Tools {
	public:
		void out(std::string str);

		void input(std::string& str);

		int to_int(const std::string& str);//string to int

		double to_float(const std::string& str);//string to float
	
		virtual GameRandom::RoleType Load_GameRandomRole(std::string& address_) = 0;

		void System(const std::string& str);
	};

	class Input :public Tools {
	public:
		GameRandom::RoleType Load_GameRandomRole(std::string& address_) override;
	};

	class Out :public Tools{
	public:
		GameRandom::RoleType Load_GameRandomRole(std::string& address_) override;
	};

	class Random:public Tools {
	public:
		GameRandom::RoleType Load_GameRandomRole(std::string& address_) override;
	};

	class File :public Tools {
	public:
		GameRandom::RoleType Load_GameRandomRole(std::string& address_) override;
	};
}

#endif // !TOOLS_H