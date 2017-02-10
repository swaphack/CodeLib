#include "Base.h"

using namespace script;


Base::Base()
:m_nAccessType(0)
{

}

Base::~Base()
{

}

int Base::getAccessType()
{
	return m_nAccessType;
}

void Base::setAccessType(int nType)
{
	m_nAccessType = nType;
}

const char* Base::getName()
{
	return m_strName.c_str();
}

void Base::setName(const char* name)
{
	if (name)
	{
		m_strName = name;
	}
}

void Base::dispose()
{
	delete this;
}
