#include "Struct.h"
#include "Function.h"
#include "Members.h"

using namespace script;

Struct::Struct()
:m_pParent(nullptr)
{
	setDataType(E_DATATYPE_STRUCT);
	m_pMembers = new Members();
}

Struct::~Struct()
{
	delete m_pMembers;
}

void Struct::setParent(Struct* pParent)
{
	this->m_pParent = pParent;
}

Struct* Struct::getParent()
{
	return this->m_pParent;
}

Variable* Struct::getVariable(const char* name)
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
		return m_pParent->getVariable(name);
	}

	return nullptr;
}

Members* Struct::getMembers()
{
	return m_pMembers;
}

bool Struct::callFunction(const char* pFuncName, std::vector<Variable*>& inputs, std::vector<Variable*>& outputs)
{
	if (pFuncName == nullptr)
	{
		return false;
	}

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

void Struct::dispose()
{
	Variable::dispose();
}

bool Struct::equal(const IVariable& var)
{
	IVariable* pVar = (IVariable*)&var;
	if (pVar->getDataType() != this->getDataType())
	{
		return false;
	}

	Struct* pStruct = dynamic_cast<Struct*>(pVar);
	if (pStruct == nullptr)
	{
		return false;
	}

	Members* pMembers = pStruct->getMembers();
	std::vector<std::string> keys = pMembers->keys();
	int count = keys.size();
	for (int i = 0; i < count; i++)
	{
		IVariable* pVar0 = pMembers->getMember(keys[i]);
		IVariable* pVar1 = m_pMembers->getMember(keys[i]);
		if (!pVar0->equal(*pVar1))
		{
			return false;
		}
	}
	return true;
}

Struct* Struct::clone()
{
	Struct* pVal = new Struct();
	pVal->setDataType(getDataType());

	std::vector<std::string> keys = m_pMembers->keys();
	for (std::vector<std::string>::iterator it = keys.begin();
		it != keys.end();
		it++)
	{
		pVal->getMembers()->addMember(m_pMembers->getMember((*it)));
	}

	Functions::iterator iterFunction = m_pFunctions.begin();
	while (iterFunction != m_pFunctions.end())
	{
		pVal->addFunction(iterFunction->second);
		iterFunction++;
	}

	pVal->setParent(getParent()->clone());

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

void Struct::initFunctions()
{
	this->addFunction(Function::create(".", [](std::vector<Variable*>& inputs, std::vector<Variable*>& outputs){
		if (inputs.size() != 2 || outputs.size() != 1)
		{
			return false;
		}
		
		if (!IS_DATATYPE(inputs[0], E_DATATYPE_STRUCT))
		{
			return false;
		}

		Struct* input = static_cast<Struct*>(inputs[0]);
		Variable* member = input->getVariable(inputs[1]->getName());
		outputs[0] = member;

		return true;
	}));
}
