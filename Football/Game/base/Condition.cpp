#include "Condition.h"

#include "../enum/eOperator.h"
#include "../enum/eInterval.h"

using namespace game;


SingleCondtion::SingleCondtion()
:m_fValue(0)
, m_nOperator(0)
{

}

SingleCondtion::~SingleCondtion()
{

}

int SingleCondtion::getOperator() const
{
	return m_nOperator;
}

void SingleCondtion::setOperator(int eOperator)
{
	m_nOperator = eOperator;
}

bool SingleCondtion::match(float value) const
{
	eOperator oper = static_cast<eOperator>(m_nOperator);
	switch (oper)
	{
	case EO_EQUAL:
		return m_fValue == value;
		break;
	case EO_NOTEQUAL:
		return m_fValue != value;
		break;
	case EO_GREATER:
		return m_fValue > value;
		break;
	case EO_LESS:
		return m_fValue < value;
		break;
	case EO_GREATER_OR_EQUAL:
		return m_fValue >= value;
		break;
	case EO_LESS_OR_EQUAL:
		return m_fValue <= value;
		break;
	default:
		break;
	}

	return false;
}

float SingleCondtion::getValue() const
{
	return m_fValue;
}

void SingleCondtion::setValue(float value)
{
	m_fValue = value;
}

//////////////////////////////////////////////////////////////////////////

IntervalCondtion::IntervalCondtion()
:m_fMinValue(0)
, m_fMaxValue(0)
, m_nInterval(0)
{

}

IntervalCondtion::~IntervalCondtion()
{

}

int IntervalCondtion::getInterval() const
{
	return m_nInterval;
}

void IntervalCondtion::setInterval(int eInterval)
{
	m_nInterval = eInterval;
}

bool IntervalCondtion::match(float value) const
{
	eInterval oper = static_cast<eInterval>(m_nInterval);

	switch (oper)
	{
	case EI_OPEN:
		return value > m_fMinValue && value < m_fMaxValue;
		break;
	case EI_CLOSE:
		return value >= m_fMinValue && value <= m_fMaxValue;
		break;
	case EI_OPEN_CLOSE:
		return value > m_fMinValue && value <= m_fMaxValue;
		break;
	case EI_CLOSE_OPEN:
		return value >= m_fMinValue && value < m_fMaxValue;
		break;
	default:
		break;
	}

	return false;
}

float IntervalCondtion::getMinValue() const
{
	return m_fMinValue;
}

void IntervalCondtion::setMinValue(float value)
{
	m_fMinValue = value;
}

float IntervalCondtion::getMaxValue() const
{
	return m_fMaxValue;
}

void IntervalCondtion::setMaxValue(float value)
{
	m_fMaxValue = value;
}
