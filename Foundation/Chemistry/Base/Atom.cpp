#include "Atom.h"

using namespace chem;

Atom::Atom()
{
	_element = 0;
}

Atom::~Atom()
{

}

void Atom::setExpression(const char* expression)
{
	if (expression)
	{
		Constitution::setExpression(expression);
		this->parseConstitution();
	}
}

int Atom::getElement()
{
	return _element;
}

void Atom::parseConstitution()
{
	const ChemElementInfo* pElementInfo = ChemPeriodicTable::getInstance()->getElementBySymbol(getExpression());
	if (pElementInfo == nullptr)
	{
		return;
	}

	_element = pElementInfo->ID;
}