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

		int random(std::uniform_int_distribution<>& dis, std::mt19937& gen);
	
		virtual GameRandom::RoleType Load_GameRandomRole(std::string& address_);
	};

	class Input :public Tools {};

	class Out :public Tools{};

	class Random:public Tools {};

	class File :public Tools {
	public:
		GameRandom::RoleType Load_GameRandomRole(std::string& address_) override;
	protected:
		std::string address;
	};
}

#endif // !TOOLS_H