#include "VariableTable.h"
#include "macros.h"

using namespace script;


VariableTable::VariableTable()
{

}

VariableTable::~VariableTable()
{
	clear();
}

void VariableTable::set(Variable* pVar)
{
	if (pVar == nullptr)
	{
		return;
	}

	std::map<std::string, Variable*>::iterator it = m_mapVariable.find(pVar->getName());

	if (it != m_mapVariable.end())
	{
		delete it->second;
		m_mapVariable.erase(it);
	}

	m_mapVariable.insert(std::make_pair(pVar->getName(), pVar));
}

Variable* VariableTable::get(const std::string& name)
{
	std::map<std::string, Variable*>::iterator it = m_mapVariable.find(name);

	if (it != m_mapVariable.end())
	{
		return it->second;
	}

	return nullptr;
}

void VariableTable::clear()
{
	std::map<std::string, Variable*>::iterator it = m_mapVariable.begin();

	while (it != m_mapVariable.end())
	{
		delete it->second;
		it++;
	}

	m_mapVariable.clear();
}
