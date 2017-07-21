#include "Real.h"
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

float Real::getValue() const
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

Real& Real::operator=(const Real& value)
{
	m_fValue = value.getValue();
	return *this;
}

Real& Real::operator+=(const Real& value)
{
	m_fValue += value.getValue();
	return *this;
}

Real& Real::operator-=(const Real& value)
{
	m_fValue -= value.getValue();
	return *this;
}

Real& Real::operator*=(const Real& value)
{
	m_fValue *= value.getValue();
	return *this;
}

Real& Real::operator/=(const Real& value)
{
	m_fValue /= value.getValue();
	return *this;
}

Real Real::operator+(const Real& value)
{
	Real real;
	real.setValue(m_fValue + value.getValue());
	return real;
}

Real Real::operator-(const Real& value)
{
	Real real;
	real.setValue(m_fValue - value.getValue());
	return real;
}

Real Real::operator*(const Real& value)
{
	Real real;
	real.setValue(m_fValue * value.getValue());
	return real;
}

Real Real::operator/(const Real& value)
{
	Real real;
	real.setValue(m_fValue / value.getValue());
	return real;
}

bool Real::operator==(const Real& value)
{
	return m_fValue == value.getValue();
}

bool Real::operator>(const Real& value)
{
	return m_fValue > value.getValue();
}

bool Real::operator<(const Real& value)
{
	return m_fValue < value.getValue();
}

bool Real::operator!=(const Real& value)
{
	return m_fValue != value.getValue();
}

bool Real::operator>=(const Real& value)
{
	return m_fValue >= value.getValue();
}

bool Real::operator<=(const Real& value)
{
	return m_fValue <= value.getValue();
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
