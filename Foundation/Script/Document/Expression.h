#pragma once

#include <string>

namespace script
{
	class Expression
	{
	public:
		Expression();
		~Expression();
	public:
		bool readLine(char* cursor, int offset);

		void setString(const char* pszWords, int nLength);
		const std::string& getString() const;
	private:
		std::string m_strWords;
	};
}