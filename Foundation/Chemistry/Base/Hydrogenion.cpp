#include "Hydrogenion.h"

using namespace chem;

Hydrogenion::Hydrogenion()
{

}

Hydrogenion::~Hydrogenion()
{

}

void Hydrogenion::setExpression(const char* expression)
{
	if (expression)
	{
		Constitution::setExpression(expression);
		this->parseConstitution();
	}
}

Elements::const_iterator Hydrogenion::elementBegin()
{
	return _elements.begin();
}

Elements::const_iterator Hydrogenion::elementEnd()
{
	return _elements.end();
}

int Hydrogenion::getCharge()
{
	return _charge;
}

void Hydrogenion::parseConstitution()
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
