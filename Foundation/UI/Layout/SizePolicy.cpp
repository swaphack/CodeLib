#include "SizePolicy.h"

using namespace ui;


SizePolicy::SizePolicy()
:m_stWidth(EST_Expanding)
, m_stHeight(EST_Expanding)
{

}

SizePolicy::~SizePolicy()
{

}

void SizePolicy::setWidthType(SizeType type)
{
	m_stWidth = type;
}

SizeType SizePolicy::getWidthType()
{
	return m_stWidth;
}

void SizePolicy::setHeightType(SizeType type)
{
	m_stHeight = type;
}

SizeType SizePolicy::getHeightType()
{
	return m_stHeight;
}
