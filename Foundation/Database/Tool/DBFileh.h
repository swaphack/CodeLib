#pragma once

#include "system.h"
#include <vector>

namespace db
{
	class DBFileReader : public sys::StreamReader
	{
	public:
		DBFileReader(const char* filepath);
		~DBFileReader();
	public:
		std::string readDBString();
	};


	class DBFileWriter : public sys::StreamWriter
	{
	public:
		DBFileWriter();
		~DBFileWriter();
	public:
		//void writeDBString(const std::string& value);
		void writeDBString(const std::string& value);
		void save(const char* filepath);
	};	
}