#include "Scope.h"
#include "Variable.h"

using namespace script;


Scope::Scope()
: m_pParent(nullptr)
, m_pHandler(nullptr)
{
}

Scope::~Scope()
{
}

void Scope::addChild(Scope* pChild)
{
	if (pChild == nullptr)
	{
		return;
	}

	if (!pChild->getParent())
	{
		C_ERROR(false, GET_TEXT(4));
		return;
	}

	if (pChild->getParent() != this)
	{
		C_ERROR(false, GET_TEXT(5));
		return;
	}

	if (getChild(pChild->getName()))
	{
		C_ERROR(false, GET_TEXT(6));
		return;
	}

	pChild->setParent(this);

	m_pChildren[pChild->getName()] = pChild;
}

void Scope::removeChild(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	Scope* pScope = getChild(name);
	if (pScope == nullptr)
	{
		return;
	}

	pScope->dispose();

	m_pChildren.erase(name);
}

void Scope::removeAllChildren()
{
	Scopes::iterator iter = m_pChildren.begin();
	while (iter != m_pChildren.end())
	{
		iter->second->dispose();
		iter++;
	}

	m_pChildren.clear();
}

Scope* Scope::getChild(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}

	Scopes::iterator iter = m_pChildren.find(name);
	if (iter == m_pChildren.end())
	{
		return nullptr;
	}

	return iter->second;
}

Scope* Scope::getParent()
{
	return m_pParent;
}

void Scope::setParent(Scope* pParent)
{
	m_pParent = pParent;
}

void Scope::addMember(Variable* pVariable)
{
	if (!pVariable)
	{
		return;
	}

	removeMember(pVariable->getName());

	m_pMembers[pVariable->getName()] = pVariable;
}

void Scope::removeMember(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	Members::iterator iter = m_pMembers.find(name);
	if (iter == m_pMembers.end())
	{
		return;
	}

	iter->second->dispose();
	m_pMembers.erase(iter);
}

void Scope::removeAllMembers()
{
	Members::iterator iter = m_pMembers.begin();
	while (iter != m_pMembers.end())
	{
		delete iter->second;
		iter++;
	}

	m_pMembers.clear();
}

Variable* Scope::getMember(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}

	Members::iterator iter = m_pMembers.find(name);
	if (iter != m_pMembers.end())
	{
		return iter->second;
	}

	if (m_pParent)
	{
		return m_pParent->getMember(name);
	}

	return nullptr;
}

void Scope::setHandler(ScopeHandler handler)
{
	m_pHandler = handler;
}

bool Scope::call(std::vector<Variable*>& inputs, std::vector<Variable*>& outputs)
{
	if (m_pHandler == nullptr)
	{
		return false;
	}

	return m_pHandler(inputs, outputs);
}

void Scope::dispose()
{
	removeAllChildren();
	removeAllMembers();
	
	Base::dispose();
}