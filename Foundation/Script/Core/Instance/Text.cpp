#include "Text.h"
using namespace script;

Text::Text()
{
	this->setDataType(E_DATATYPE_TEXT);
}

Text::~Text()
{

}

void Text::setValue(const char* value)
{
	if (value)
	{
		m_strValue = value;
	}
}

const char* Text::getValue()
{
	return m_strValue.c_str();
}

Text* Text::clone()
{
	Text* pVar = new Text();
	pVar->setDataType(getDataType());
	pVar->setValue(getValue());
	return pVar;
}


Text* Text::alloct(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}
	Text* pVal = this->clone();
	pVal->setName(name);
	return pVal;
}