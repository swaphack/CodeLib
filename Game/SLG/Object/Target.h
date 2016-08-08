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
	class Target : public sys::Object , public sys::Name, public Identify
	{
	public:
		Target();
		virtual ~Target();
	public:
	private:
		// 目标编号
		static int g_TargetID;
	};
}