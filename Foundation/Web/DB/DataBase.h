#pragma once

#include <string>
#include <vector>

namespace web
{
	// 数据库
	class DataBase
	{
	public:
		DataBase();
		virtual ~DataBase();
	public:
		// 加载表
		void loadTable(const std::string& name, const std::vector<std::string>& members);
	};
}