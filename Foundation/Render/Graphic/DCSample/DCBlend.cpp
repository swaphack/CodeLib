#pragma once

#include "DCBlend.h"

using namespace render;

DCBlend::DCBlend()
:Src(0)
, Dest(0)
{

}

DCBlend::~DCBlend()
{

}

void DCBlend::draw()
{
	glBlendFunc(Src, Dest);
}
