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
	// ����
	class Target : public sys::Object , public sys::Name, public Identify
	{
	public:
		Target();
		virtual ~Target();
	public:
	private:
		// Ŀ����
		static int g_TargetID;
	};
}