#pragma once

#include "macros.h"

#include <string>

namespace tribe
{
	// 人类
	class Human
	{
	public:
		Human();
		virtual ~Human();
	public:
		// 获取出生日
		inline int getBirthday() const { return _birthday; }
		// 设置出生日
		inline void setBirthday(int val) { _birthday = val; }
		// 获取死亡日
		inline int getDeathday() const { return _deathday; }
		// 设置死亡日
		inline void setDeathday(int val) { _deathday = val; }
		// 获取性别
		inline int getSex() const { return _sex; }
		// 设置性别
		inline void setSex(int val) { _sex = val; }
		// 获取姓名
		inline std::string getName() const { return _name; }
		// 设置姓名
		inline void setName(std::string val) { _name = val; }
	private:
		// 出生日
		int _birthday;
		// 死亡日
		int _deathday;
		// 性别
		int _sex;
		// 姓名
		std::string _name;
	};
}