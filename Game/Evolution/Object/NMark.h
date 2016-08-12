#pragma once

#include <string>

namespace nature
{
	class NMark
	{
	public:
		NMark();
		virtual ~NMark();
	public:
		// 设置编号
		void setID(int ID);
		// 获取编号
		int getID();
		// 设置名称
		void setName(const char* name);
		// 获取名称
		const char* getName();
	private:
		int _ID; // 编号
		std::string _name; // 名称
	};
}

