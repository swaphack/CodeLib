#pragma once

#include "Target.h"
#include "../Time/import.h"

namespace slg
{
	class Human : public Target
	{
	public:
		Human(Human* father, Human* monther);
		virtual ~Human() {}
	public:
		// 姓名
		const char* getName();
		// 设置姓名
		void setName(const char* name);

		// 出生日期
		const DateTime* getBirthDay();
	protected:
	private:
	};
}