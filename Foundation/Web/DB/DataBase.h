#pragma once

#include <string>
#include <vector>

namespace web
{
	// ���ݿ�
	class DataBase
	{
	public:
		DataBase();
		virtual ~DataBase();
	public:
		// ���ر�
		void loadTable(const std::string& name, const std::vector<std::string>& members);
	};
}