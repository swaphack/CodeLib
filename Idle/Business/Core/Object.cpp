#include "Object.h"

using namespace business;
#include <ctime>


uint64_t business::Object::s_nID = 0;

business::Object::Object()
{
	m_nID = ++s_nID;
	m_nCreateTime = time(nullptr);
}

business::Object::~Object()
{

}

uint64_t business::Object::getID()
{
	return m_nID;
}

void business::Object::setName(const std::string& strName)
{
	m_strName = strName;
}

const std::string& business::Object::getName()
{
	return m_strName;
}

uint64_t business::Object::getCreateTime()
{
	return m_nCreateTime;
}
