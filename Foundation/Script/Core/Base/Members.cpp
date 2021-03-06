#include "Members.h"
#include "Variable.h"

using namespace script;

Members::Members()
{

}

Members::~Members()
{
	this->removeAllMembers();
}

void Members::addMember(Variable* pVariable)
{
	if (!pVariable)
	{
		return;
	}

	removeMember(pVariable->getName());

	m_varMembers[pVariable->getName()] = pVariable;
}

void Members::removeMember(const std::string& name)
{
	VarMembers::iterator iter = m_varMembers.find(name);
	if (iter == m_varMembers.end())
	{
		return;
	}

	iter->second->dispose();
	m_varMembers.erase(iter);
}

void Members::removeAllMembers()
{
	VarMembers::iterator iter = m_varMembers.begin();
	while (iter != m_varMembers.end())
	{
		delete iter->second;
		iter++;
	}

	m_varMembers.clear();
}

Variable* Members::getMember(const std::string& name)
{
	if (name.empty())
	{
		return nullptr;
	}

	VarMembers::iterator iter = m_varMembers.find(name);
	if (iter != m_varMembers.end())
	{
		return iter->second;
	}

	return nullptr;
}

std::vector<std::string> Members::keys()
{
	std::vector<std::string> keys;

	VarMembers::iterator iter = m_varMembers.begin();
	while (iter != m_varMembers.end())
	{
		keys.push_back(iter->first);
		iter++;
	}

	return keys;
}