#include "SingalSet.h"

using namespace script;

static SingalSet* s_KeyWord = nullptr;

SingalSet::SingalSet()
{

}

SingalSet::~SingalSet()
{

}

SingalSet* SingalSet::getInstance()
{
	if (s_KeyWord == nullptr)
	{
		s_KeyWord = new SingalSet();
		s_KeyWord->init();
	}

	return s_KeyWord;
}

void SingalSet::append(const char* keyword)
{
	if (keyword == nullptr)
	{
		return;
	}

	m_vSingals.push_back(keyword);
}

int SingalSet::contain(const char* keyword)
{
	if (keyword == nullptr)
	{
		return -1;
	}

	for (Words::const_iterator iter = m_vSingals.begin(); iter != m_vSingals.end(); iter++)
	{
		char* ptr = (char*)strstr(keyword, (*iter).c_str());
		if (ptr != nullptr && (ptr - keyword) == 0)
		{
			return (*iter).size();
		}
	}

	return -1;
}

void SingalSet::clear()
{
	m_vSingals.clear();
}

void SingalSet::init()
{
	append(">>=");
	append("<<=");

	append("|=");
	append("^=");
	append("&=");
	append("-=");
	append("+=");
	append("%=");
	append("*=");
	append("/=");

	append("||");
	append("&&");
	append("!=");
	append("==");
	append("<=");
	append(">=");

	append(">>");
	append("<<");

	append("++");
	append("--");
	append("->");


	append("|");
	append("^");
	append("&");
	append("<");
	append(">");

	append("?");
	append(":");

	append(".");
	append("=");

	append(",");
	append("+");
	append("-");
	append("*");
	append("/");

	append("~");

	append("!");
	
	append("{");
	append("}");
	append("(");
	append(")");
	append("[");
	append("]");
}
