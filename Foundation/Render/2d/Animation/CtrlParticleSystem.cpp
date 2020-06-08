#include "CtrlParticleSystem.h"
#include "system.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"
#include "Common/Tool/VertexTool.h"
using namespace render;

CtrlParticleSystem::CtrlParticleSystem()
:_particleCount(0)
{

}

CtrlParticleSystem::~CtrlParticleSystem()
{

}

bool CtrlParticleSystem::init()
{
	if (!CtrlAnimation::init())
	{
		return false;
	}
	
	return true;
}

void CtrlParticleSystem::setCount(uint32_t count)
{
	_particleCount = count;
}

uint32_t CtrlParticleSystem::getCount()
{
	return _particleCount;
}

void CtrlParticleSystem::updateSelf(float interval)
{

}

void CtrlParticleSystem::onParticleEndHandler()
{
}
