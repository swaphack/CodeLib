#pragma once
#include <string>

namespace sys
{
	class Directory
	{
	public:
		static void getDir(const char* filepath, std::string& dir);
	protected:
	private:
	};
}