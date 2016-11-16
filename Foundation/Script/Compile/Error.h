#pragma once

#include <string>

namespace script
{
	/**
	*	����
	*/
	class Error
	{
	public:
		Error(const char* msg);
		~Error();
	public:
		const char* getMessage();
	private:
		// ������Ϣ
		std::string m_sErrorMsg;
	};

	extern Error* makeError(const char* format, ...);
}