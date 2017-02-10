#include "Environment.h"

using namespace script;

static Environment* s_pEnvironment = nullptr;


Environment::Environment()
{

}

Environment::~Environment()
{

}

Environment* Environment::getInstance()
{
	if (s_pEnvironment == nullptr)
	{
		s_pEnvironment = new Environment();
	}

	return s_pEnvironment;
}

void Environment::addVariable(Variable* pVariable)
{
	if (!pVariable)
	{
		return;
	}

	removeVariable(pVariable->getName());

	m_pVariables[pVariable->getName()] = pVariable;
}

void Environment::removeVariable(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	Variables::iterator iter = m_pVariables.find(name);
	if (iter == m_pVariables.end())
	{
		return;
	}

	iter->second->dispose();
	m_pVariables.erase(iter);
}

void Environment::removeAllVariables()
{
	Variables::iterator iter = m_pVariables.begin();
	while (iter != m_pVariables.end())
	{
		delete iter->second;
		iter++;
	}

	m_pVariables.clear();
}

Variable* Environment::getVariable(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}

	Variables::iterator iter = m_pVariables.find(name);
	if (iter != m_pVariables.end())
	{
		return iter->second;
	}

	return nullptr;
}

// void Environment::addStruct(Struct* pStruct)
// {
// 	if (!pStruct)
// 	{
// 		return;
// 	}
// 
// 	removeStruct(pStruct->getName());
// 
// 	m_pStructs[pStruct->getName()] = pStruct;
// }
// 
// void Environment::removeStruct(const char* name)
// {
// 	if (name == nullptr)
// 	{
// 		return;
// 	}
// 
// 	Structs::iterator iter = m_pStructs.find(name);
// 	if (iter == m_pStructs.end())
// 	{
// 		return;
// 	}
// 
// 	iter->second->dispose();
// 	m_pStructs.erase(iter);
// }
// 
// void Environment::removeAllStructs()
// {
// 	Structs::iterator iter = m_pStructs.begin();
// 	while (iter != m_pStructs.end())
// 	{
// 		delete iter->second;
// 		iter++;
// 	}
// 
// 	m_pStructs.clear();
// }
// 
// Struct* Environment::getStruct(const char* name)
// {
// 	if (name == nullptr)
// 	{
// 		return nullptr;
// 	}
// 
// 	Structs::iterator iter = m_pStructs.find(name);
// 	if (iter != m_pStructs.end())
// 	{
// 		return iter->second;
// 	}
// 
// 	return nullptr;
// }

void Environment::addFunction(Function* pFunction)
{
	if (!pFunction)
	{
		return;
	}

	removeFunction(pFunction->getName());

	m_pFunctions[pFunction->getName()] = pFunction;
}

void Environment::removeFunction(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	Functions::iterator iter = m_pFunctions.find(name);
	if (iter == m_pFunctions.end())
	{
		return;
	}

	iter->second->dispose();
	m_pFunctions.erase(iter);
}

void Environment::removeAllFunctions()
{
	Functions::iterator iter = m_pFunctions.begin();
	while (iter != m_pFunctions.end())
	{
		delete iter->second;
		iter++;
	}

	m_pFunctions.clear();
}

Function* Environment::getFunction(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}

	Functions::iterator iter = m_pFunctions.find(name);
	if (iter == m_pFunctions.end())
	{
		return nullptr;
	}

	return iter->second;
}

Scope* Environment::getRoot()
{
	return m_pRoot;
}

void Environment::dispose()
{
	removeAllVariables();
	removeAllFunctions();
	//removeAllStructs();
}

Environment* getEnv()
{
	return Environment::getInstance();
}
