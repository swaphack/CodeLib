#include "Scope.h"
#include "Variable.h"
#include "CodeBlock.h"

using namespace script;


Scope::Scope()
: m_pParent(nullptr)
{
	m_pCodeBlock = new CodeBlock();
}

Scope::~Scope()
{
	delete m_pCodeBlock;
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

	pScope->disponse();

	m_pChildren.erase(name);
}

void Scope::removeAllChildren()
{
	Scopes::iterator iter = m_pChildren.begin();
	while (iter != m_pChildren.end())
	{
		iter->second->disponse();
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

	iter->second->disponse();
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

CodeBlock* Scope::getCodeBlock()
{
	return m_pCodeBlock;
}

bool Scope::call(std::vector<Variable*>& inputs, std::vector<Variable*>& outputs)
{
	if (m_pCodeBlock)
	{
		return m_pCodeBlock->run(inputs, outputs);
	}
	return true;
}

void Scope::disponse()
{
	removeAllChildren();
	removeAllMembers();
	
	Base::disponse();
}
