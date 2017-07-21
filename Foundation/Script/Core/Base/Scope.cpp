#include "Scope.h"
#include "Variable.h"
#include "Members.h"

using namespace script;


Scope::Scope()
: m_pParent(nullptr)
, m_pHandler(nullptr)
{
	m_pMembers = new Members();
}

Scope::~Scope()
{
	delete m_pMembers;
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

Variable* Scope::getMember(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}

	Variable* pVar = m_pMembers->getMember(name);
	if (pVar)
	{
		return pVar;
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
	Base::dispose();
}