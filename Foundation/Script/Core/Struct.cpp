#include "Struct.h"

using namespace script;

Struct::Struct()
:m_pParent(nullptr)
{
	setDataType(E_DATATYPE_STRUCT);
}

Struct::~Struct()
{
	this->removeAllMembers();
}

void Struct::addMember(Variable* pVariable)
{
	if (!pVariable)
	{
		return;
	}

	removeMember(pVariable->getName());

	m_pMembers[pVariable->getName()] = pVariable;
}

void Struct::removeMember(const char* name)
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

void Struct::removeAllMembers()
{
	Members::iterator iter = m_pMembers.begin();
	while (iter != m_pMembers.end())
	{
		delete iter->second;
		iter++;
	}

	m_pMembers.clear();
}

bool Struct::inherit(Struct* pParent)
{
	if (this->m_pParent == nullptr)
	{
		return false;
	}

	this->m_pParent = pParent->clone();

	return true;
}

Struct* Struct::getParent()
{
	return this->m_pParent;
}

Variable* Struct::getMember(const char* name)
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

bool Struct::callFunction(const char* pFuncName, std::vector<Variable*>& inputs, std::vector<Variable*>& outputs)
{
	if (Variable::callFunction(pFuncName, inputs, outputs))
	{
		return true;
	}

	if (m_pParent && m_pParent->callFunction(pFuncName, inputs, outputs))
	{
		return true;
	}

	return false;
}

void Struct::disponse()
{
	removeAllMembers();
	Variable::disponse();
}

Struct* Struct::clone()
{
	Struct* pVal = new Struct();
	pVal->setDataType(getDataType());
	pVal->inherit(getParent());

	Members::iterator iterMember = m_pMembers.begin();
	while (iterMember != m_pMembers.end())
	{
		pVal->addMember(iterMember->second->clone());
		iterMember++;
	}

	Functions::iterator iterFunction = m_pFunctions.begin();
	while (iterFunction != m_pFunctions.end())
	{
		pVal->addFunction(iterFunction->second);
		iterMember++;
	}

	return pVal;
}

Struct* Struct::alloct(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}

	Struct* pVal = this->clone();
	pVal->setName(name);
	return pVal;
}