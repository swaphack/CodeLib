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
	class Target : public sys::Object
	{
	public:
		Target();
		virtual ~Target();
	public:
		// ����
		const char* getName();
		// ��������
		void setName(const char* name);
	private:
		// ����
		std::string _name;
		// Ŀ����
		static int g_TargetID;
	};
}