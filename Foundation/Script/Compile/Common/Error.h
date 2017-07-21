#pragma once

#include <string>

namespace script
{
	/**
	*	´íÎó
	*/
	class Error
	{
	public:
		Error(const char* msg);
		~Error();
	public:
		const char* getMessage();
	private:
		// ´íÎóĞÅÏ¢
		std::string m_sErrorMsg;
	};

	extern Error* makeError(const char* format, ...);
}