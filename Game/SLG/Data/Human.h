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
		// ����
		const char* getName();
		// ��������
		void setName(const char* name);

		// ��������
		const DateTime* getBirthDay();
	protected:
	private:
	};
}