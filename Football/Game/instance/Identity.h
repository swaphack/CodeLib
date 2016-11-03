#pragma once

#include <string>

namespace game
{
	class Identity
	{
	public:
		Identity();
		virtual ~Identity();
	public:
		/**
		*	获取编号
		*/
		int getID();
		/**
		*	设置编号
		*/
		void setID(int nID);
		/**
		*	获取名字
		*/
		const char* getName();
		/**
		*	设置名字
		*/
		void setName(const char* name);
	private:
		int	_id;
		std::string _name;
	};
}