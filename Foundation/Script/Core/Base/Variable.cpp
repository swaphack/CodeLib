#include "Variable.h"

#include "Function.h"

using namespace script;


Variable::Variable()
:m_nDataType(0)
{

}

Variable::~Variable()
{

}

int Variable::getDataType()
{
	return m_nDataType;
}

void Variable::setDataType(int nDataType)
{
	m_nDataType = nDataType;
}


void Variable::addFunction(Function* pFunction)
{
	if (!pFunction)
	{
		return;
	}

	removeFunction(pFunction->getName());

	m_pFunctions[pFunction->getName()] = pFunction;
}

void Variable::removeFunction(const std::string& name)
{
	Functions::iterator iter = m_pFunctions.find(name);
	if (iter == m_pFunctions.end())
	{
		return;
	}

	iter->second->dispose();
	m_pFunctions.erase(iter);
}

void Variable::removeAllFunctions()
{
	Functions::iterator iter = m_pFunctions.begin();
	while (iter != m_pFunctions.end())
	{
		delete iter->second;
		iter++;
	}

	m_pFunctions.clear();
}

Function* Variable::getFunction(const std::string& name)
{
	Functions::iterator iter = m_pFunctions.find(name);
	if (iter == m_pFunctions.end())
	{
		return nullptr;
	}

	return iter->second;
}

bool Variable::callFunction(const std::string& pFuncName, std::vector<Variable*>& inputs, std::vector<Variable*>& outputs)
{
	Function* pFunc = getFunction(pFuncName);
	if (pFunc == nullptr)
	{
		return false;
	}

	return pFunc->call(inputs, outputs);
}

void Variable::dispose()
{
	removeAllFunctions();

	Base::dispose();
}

bool Variable::equal(const IVariable& var)
{
	return this == &var;
}

Variable* Variable::clone()
{
	Variable* pVar = new Variable();
	pVar->setDataType(getDataType());
	return pVar;
}

Variable* Variable::alloct(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}
	Variable* pVal = this->clone();
	pVal->setName(name);
	return pVal;
}

void Variable::initFunctions()
{

}