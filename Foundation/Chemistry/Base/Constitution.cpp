#include "Constitution.h"

using namespace chem;

Constitution::Constitution()
{

}

Constitution::~Constitution()
{

}

void Constitution::setExpression(const char* expression)
{
	_expression = expression;
}

const char* Constitution::getExpression()
{
	return _expression.c_str();
}

