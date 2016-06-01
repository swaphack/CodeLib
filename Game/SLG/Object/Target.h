#pragma once

#include <string>
#include "system.h"

// template<>
// struct std::less<slg::Target*>
// {
// 	bool operator()(slg::Target*_X, slg::Target* _Y) const
// 	{
// 		return _X->getID() < _Y->getID();
// 	}
// };

namespace slg
{
	// 对象
	class Target : public sys::Object
	{
	public:
		Target();
		virtual ~Target();
	public:
		// 名称
		const char* getName();
		// 设置名称
		void setName(const char* name);
	private:
		// 名称
		std::string _name;
		// 目标编号
		static int g_TargetID;
	};
}