#include "Bit.h"

using namespace sys;


Bit::Bit()
{

}

Bit::~Bit()
{

}

bool Bit::isZero(uint64_t idx) const
{
	if (idx >= m_nLength)
	{
		return true;
	}

	return m_pData[idx] == 0;
}

void Bit::set(uint64_t idx, uint8_t value)
{
	if (idx >= m_nLength)
	{
		return;
	}

	m_pData[idx] = value;
}

void Bit::setZero(uint64_t idx)
{
	this->set(idx, 0);
}

void Bit::setOne(uint64_t idx)
{
	this->set(idx, 1);
}
