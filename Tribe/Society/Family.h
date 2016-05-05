#pragma once

#include "../People/Person.h"

#include <vector>

namespace tribe
{
	class Person;
	// 家族
	class Family
	{
	public:
	protected:
	private:
		// 父亲
		Person* _father;
		// 母亲
		Person* _mother;
		// 自己
		Person* _self;
		// 儿女
		std::vector<Person*> _children;
	};
}