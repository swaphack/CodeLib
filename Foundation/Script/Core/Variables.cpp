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
	this->removeAllFunctions();

	this->addFunction(Function::create("+", [](std::vector<Variable*>& inputs, std::vector<Variable*>& outputs){
		if (inputs.size() != 2 || outputs.size() != 1)
			return false;
		if (!IS_DATATYPE(inputs[0], E_DATATYPE_REAL)
			|| !IS_DATATYPE(inputs[1], E_DATATYPE_REAL)
			|| !IS_DATATYPE(outputs[0], E_DATATYPE_REAL))
		{
			return false;
		}

		Real* input1 = static_cast<Real*>(inputs[0]);
		Real* input2 = static_cast<Real*>(inputs[1]);
		Real* output = static_cast<Real*>(outputs[0]);
		
		output->setValue(input1->getValue() + input2->getValue());

		return true;
	}));
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
