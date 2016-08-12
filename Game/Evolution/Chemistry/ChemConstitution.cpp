#include "ChemConstitution.h"
#include "ChemDocument.h"
#include "ChemPeriodicTable.h"

using namespace nature;

ChemConstitution::ChemConstitution()
{

}

ChemConstitution::~ChemConstitution()
{

}

void ChemConstitution::setExpression(const char* expression)
{
	_expression = expression;
}

const char* ChemConstitution::getExpression()
{
	return _expression.c_str();
}


//////////////////////////////////////////////////////////////////////////

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
		ChemConstitution::setExpression(expression);
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

//////////////////////////////////////////////////////////////////////////

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
		ChemConstitution::setExpression(expression);
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

	const ChemElementInfo* pElementInfo = nullptr;
	pNode->foreach([&](const std::string& symbol, const std::string& number){
		pElementInfo = ChemPeriodicTable::getInstance()->getElementBySymbol(symbol.c_str());
		if (pElementInfo)
		{
			_elements[pElementInfo->ID] += atoi(number.c_str());
		}
	});

	delete pNode;
	delete pDoc;
}

//////////////////////////////////////////////////////////////////////////

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
		ChemConstitution::setExpression(expression);
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

	const ChemElementInfo* pElementInfo = nullptr;
	pNode->foreach([&](const std::string& symbol, const std::string& number){
		pElementInfo = ChemPeriodicTable::getInstance()->getElementBySymbol(symbol.c_str());
		if (pElementInfo)
		{
			_elements[pElementInfo->ID] += atoi(number.c_str());
		}
	});

	delete pNode;
	delete pDoc;
}
