#pragma once

#include "../People/Person.h"

#include <vector>

namespace tribe
{
	class Person;
	// ����
	class Family
	{
	public:
	protected:
	private:
		// ����
		Person* _father;
		// ĸ��
		Person* _mother;
		// �Լ�
		Person* _self;
		// ��Ů
		std::vector<Person*> _children;
	};
}