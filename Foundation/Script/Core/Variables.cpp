#include "Variables.h"
#include "common.h"
#include "Function.h"
using namespace script;


Real::Real()
:m_fValue(0)
{
	this->setDataType(E_DATATYPE_REAL);
}

Real::Real(Real& value)
: Real()
{
	*this = value;
}

Real::~Real()
{

}

void Real::setValue(float value)
{
	m_fValue = value;
}

float Real::getValue()
{
	return m_fValue;
}

Real Real::operator + (Real& value)
{
	Real temp;
	temp.setValue(value.getValue() + getValue());
	return temp;
}

Real Real::operator - (Real& value)
{
	Real temp;
	temp.setValue(value.getValue() - getValue());
	return temp;
}

Real Real::operator * (Real& value)
{
	Real temp;
	temp.setValue(value.getValue() * getValue());
	return temp;
}

Real Real::operator / (Real& value)
{
	C_ERROR(value.getValue() != 0, GET_TEXT(7));

	Real temp;
	temp.setValue(getValue() / value.getValue());
	return temp;
}

Real& Real::operator = (Real& value)
{
	setValue(value.getValue());

	return *this;
}


Real& Real::operator += (Real& value)
{
	setValue(value.getValue() + getValue());

	return *this;
}

Real& Real::operator -= (Real& value)
{
	setValue(value.getValue() - getValue());

	return *this;
}

Real& Real::operator *= (Real& value)
{
	setValue(value.getValue() * getValue());

	return *this;
}

Real& Real::operator /= (Real& value)
{
	C_ERROR(value.getValue() != 0, GET_TEXT(7));

	setValue(getValue() / value.getValue());

	return *this;
}


Real* Real::clone()
{
	Real* pVar = new Real();
	pVar->setDataType(getDataType());
	pVar->setValue(getValue());
	return pVar;
}

Real* Real::alloct(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}
	Real* pVal = this->clone();
	pVal->setName(name);
	return pVal;
}

void Real::initFunctions()
{
// 	this->removeAllFunctions();
// 
// 	this->addFunction(Function::create("+", [](std::vector<Variable*>& inputs, std::vector<Variable*>& outputs){
// 		if (outputs.size() != 1)
// 		{
// 			return false;
// 		}
// 		Real* pValue = nullptr;
// 		Real* pSum = static_cast<Real*>(outputs[0]);
// 		for (int i = 0; i < inputs.size(); i++)
// 		{
// 			if (inputs[i]->getDataType() != E_DATATYPE_REAL) 
// 			{
// 				return false;
// 			}
// 			pValue = static_cast<Real*>(inputs[i]);
// 			*pSum += *pValue;
// 		}
// 
// 		return true;
// 	}));
}

//////////////////////////////////////////////////////////////////////////


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

//////////////////////////////////////////////////////////////////////////

None::None()
{
	this->setDataType(E_DATATYPE_NULL);
}

None::~None()
{

}

void* None::getValue()
{
	return nullptr;
}

None* None::clone()
{
	None* pVar = new None();
	pVar->setDataType(getDataType());
	return pVar;
}

None* None::alloct(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}
	None* pVal = this->clone();
	pVal->setName(name);
	return pVal;
}
