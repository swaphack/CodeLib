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

const std::string& Base::getName()
{
	return m_strName;
}

void Base::setName(const std::string& name)
{
	m_strName = name;
}

void Base::dispose()
{
	delete this;
}
