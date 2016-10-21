#include "Expression.h"

using namespace script;


Expression::Expression()
{

}

Expression::~Expression()
{

}

bool Expression::readLine(char* cursor, int offset)
{

}

void Expression::setString(const char* pszWords, int nLength)
{
	m_strWords = std::string(pszWords, nLength);
}

const std::string& Expression::getString() const
{
	return m_strWords;
}
