#pragma once

#include "system.h"
#include <vector>

namespace db
{
	// 数据库文件读取
	class DBFileReader : public sys::StreamReader
	{
	public:
		DBFileReader();
		virtual ~DBFileReader();
	public:
		bool load(const char* filepath);
		std::string readDBString();
	};

	// 数据库文件保存
	class DBFileWriter : public sys::StreamWriter
	{
	public:
		DBFileWriter();
		virtual ~DBFileWriter();
	public:
		//void writeDBString(const std::string& value);
		void writeDBString(const std::string& value);
		bool save(const char* filepath);
	};	
}