#include "Molecule.h"

using namespace chem;

Molecule::Molecule()
{

}

Molecule::~Molecule()
{

}

void Molecule::setExpression(const char* expression)
{
	if (expression)
	{
		Constitution::setExpression(expression);
		this->parseConstitution();
	}
}

Elements::const_iterator Molecule::elementBegin()
{
	return _elements.begin();
}

Elements::const_iterator Molecule::elementEnd()
{
	return _elements.end();
}

void Molecule::parseConstitution()
{
	char* ptr = (char*)getExpression();

	ChemDocument* pDoc = new ChemDocument();
	ChemNode* pNode = pDoc->loadMolecular(ptr);
	if (pNode == nullptr)
	{
		delete pDoc;
	}

	const Element* pElement = nullptr;
	pNode->foreach([&](const std::string& symbol, const std::string& number){
		pElement = PeriodicTable::getInstance()->getElementBySymbol(symbol.c_str());
		if (pElement)
		{
			_elements[pElement->ID] += atoi(number.c_str());
		}
	});

	delete pNode;
	delete pDoc;
}