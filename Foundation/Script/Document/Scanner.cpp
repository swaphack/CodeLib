#include "Scanner.h"
#include "Block.h"
#include "Expression.h"

using namespace script;

Scanner::Scanner()
{

}

void Scanner::setBlock(Block* block)
{
	m_pBlock = block;
}

bool Scanner::read(const char* ptr, int size)
{
	if (ptr == nullptr || size <= 0)
	{
		return false;
	}

	m_pContent = (char*)ptr;
	m_nSize = size;
	m_nOffset = 0;

	this->parse();
}

bool Scanner::parse()
{
	if (m_pBlock == nullptr)
	{
		return false;
	}


}

Block* Scanner::readBlock()
{

}

Expression* Scanner::readExpression()
{

}


