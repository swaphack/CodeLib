#include "Block.h"
#include "Expression.h"

using namespace script;

Block::Block()
:m_strName("")
{

}

Block::~Block()
{
	removeAllBlocks();
	removeAllExpressions();
}

void Block::setName(const char* name)
{
	if (name)
	{
		m_strName = name;
	}
}

const char* Block::getName()
{
	return m_strName.c_str();
}

void Block::addBlock(Block* block)
{
	if (block == nullptr)
	{
		return;
	}

	removeBlock(block->getName());

	m_pBlocks[block->getName()] = block;
}

Block* Block::getBlock(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}

	Blocks::iterator iter = m_pBlocks.find(name);
	if (iter != m_pBlocks.end())
	{
		return iter->second;
	}

	return nullptr;
}

void Block::removeBlock(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	Blocks::iterator iter = m_pBlocks.find(name);
	if (iter == m_pBlocks.end())
	{
		return;
	}

	delete iter->second;

	m_pBlocks.erase(iter);
}

void Block::removeAllBlocks()
{
	Blocks::iterator iter = m_pBlocks.begin();
	while (iter != m_pBlocks.end())
	{
		delete iter->second;
		iter++;
	}

	m_pBlocks.clear();
}


void Block::addExpression(Expression* expression)
{
	if (expression == nullptr)
	{
		return;
	}

	m_pExpressions.push_back(expression);
}

void Block::removeAllExpressions()
{
	Expressions::iterator iter = m_pExpressions.begin();
	while (iter != m_pExpressions.end())
	{
		delete *iter;
		iter++;
	}

	m_pExpressions.clear();
}
