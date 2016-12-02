#include "SingalSet.h"

using namespace script;

static SingalSet* s_name = nullptr;

SingalSet::SingalSet()
{

}

SingalSet::~SingalSet()
{

}

SingalSet* SingalSet::getInstance()
{
	if (s_name == nullptr)
	{
		s_name = new SingalSet();
		s_name->init();
	}

	return s_name;
}

void SingalSet::addOperator(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	int len = strlen(name);
	for (int i = 1; i <= len; i ++)
	{
		if (m_vOperatorSingals.size() < i)
		{
			std::vector<std::string> operatorAry;
			m_vOperatorSingals.push_back(operatorAry);
		}
	}

	m_vOperatorSingals[len - 1].push_back(name);
}

int SingalSet::containOperator(const char* name)
{
	if (name == nullptr)
	{
		return -1;
	}

	int len = strlen(name);
	if (len	<= 0)
	{
		return -1;
	}

	if (m_vOperatorSingals.size() < len)
	{
		return -1;
	}

	for (std::vector<std::string>::const_iterator iter = m_vOperatorSingals[len - 1].begin();
		iter != m_vOperatorSingals[len - 1].end();
		iter++)
	{
		if ((*iter).compare(name) == 0)
		{
			return len;
		}
	}

	return len;
}

void SingalSet::clear()
{
	m_vOperatorSingals.clear();
}

void SingalSet::init()
{
	addOperator("{", 0);
	addOperator("}", 0);

	addOperator("->", 1);
	addOperator(".", 1);
	addOperator("(", 1);
	addOperator(")", 1);
	addOperator("[", 1);
	addOperator("]", 1);

	addOperator("++", 2);
	addOperator("--", 2);
	addOperator("~", 2);
	addOperator("!", 2);

	addOperator("*", 3);
	addOperator("/", 3);
	addOperator("%", 3);

	addOperator("+", 4);
	addOperator("-", 4);

	addOperator(">>", 5);
	addOperator("<<", 5);

	addOperator("<", 6);
	addOperator(">", 6);
	addOperator("<=", 6);
	addOperator(">=", 6);

	addOperator("!=", 7);
	addOperator("==", 7);

	addOperator("&", 8);

	addOperator("^", 9);

	addOperator("|", 10);

	addOperator("&&", 11);

	addOperator("||", 12);

	addOperator("?", 13);
	addOperator(":", 13);

	addOperator("=", 14);
	addOperator("/=", 14);
	addOperator("*=", 14);
	addOperator("%=", 14);
	addOperator("+=", 14);
	addOperator("-=", 14);
	addOperator("<<=", 14);
	addOperator(">>=", 14);
	addOperator("&=", 14);
	addOperator("^=", 14);
	addOperator("|=", 14);
	
	addOperator(",", 15);
}