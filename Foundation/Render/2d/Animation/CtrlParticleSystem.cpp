#include "CtrlParticleSystem.h"
#include "system.h"
using namespace render;

ParticleNode::ParticleNode()
{

}

ParticleNode::~ParticleNode()
{

}

void ParticleNode::draw()
{
	ColorNode::draw();

	G_DRAWCOMMANDER->addCommand(DCTexture::create(0, &_texRect, _color, _opacity, _blend));
}

void ParticleNode::update(float interval)
{
	if (_liftTime <= 0)
	{
		return;
	}

	_liftTime -= interval;

	_colorInit.add(_colorAcceleration);
	_position.add(_speedAcceleration);
	_scale.add(_scaleAcceleration);
	_rotation.add(_angleAcceleration);

	convertColor4FTo4B(_colorInit, _color);
	TextureTool::setTexture2DVertexts(&_texRect, sys::Vector3::Zero, _volume, _anchor);

	Tool::convertToOGLPoisition(_position, _obPosition);
}

void ParticleNode::initSelf()
{
	ColorNode::initSelf();

	convertColor4BTo4F(_color, _colorInit);

	sys::Size size = sys::Size(_volume.width, _volume.height);
	sys::Rect rect = sys::Rect(0, 0, _volume.width, _volume.height);

	TextureTool::setTexture2DCoords(&_texRect, size, rect);
	TextureTool::setTexture2DVertexts(&_texRect, sys::Vector3::Zero, _volume, _anchor);
}

//////////////////////////////////////////////////////////////////////////

CtrlParticleSystem::CtrlParticleSystem()
:_particleCount(0)
{

}

CtrlParticleSystem::~CtrlParticleSystem()
{

}

bool CtrlParticleSystem::init()
{
	if (!Animation::init())
	{
		return false;
	}
	
	return true;
}

void CtrlParticleSystem::setCount(uint32 count)
{
	if (_particleCount == count) 
	{
		return;
	}
	this->removeAllChildren();

	_particleCount = count;

	// for test
	for (uint32 i = 0; i < count; i++)
	{
		ParticleNode* node = createParticle();
		if (node)
		{
			this->addChild(node);
		}
	}
}

uint32 CtrlParticleSystem::getCount()
{
	return _particleCount;
}

void CtrlParticleSystem::updateSelf(float interval)
{
	std::vector<ParticleNode*> removeNodes;

	std::vector<sys::Object*>::iterator it;
	it = _children.begin();
	while (it != _children.end())
	{
		ParticleNode* node = dynamic_cast<ParticleNode*>(*it);
		if (node)
		{
			if (node->getLifeTime() <= 0)
			{
				removeNodes.push_back(node);
			}
			else
			{
				node->update(interval);
			}
		}
		it++;
	}

	std::vector<ParticleNode*>::iterator rIt = removeNodes.begin();
	while (rIt != removeNodes.end())
	{
		onParticleEndHandler();
		(*rIt)->removeFromParent();
		rIt++;
	}
}

ParticleNode* CtrlParticleSystem::createParticle()
{
	float x = 0;
	float y = 0;
	float z = 0;

	float life = 0;

	float r = 0;
	float g = 0;
	float b = 0;
	float a = 0;

	float rx = 0;
	float ry = 0;
	float rz = 0;

	sys::Random* rand = sys::Random::getInstance();

	rand->setRange(0, 2);
	x = rand->getNextNumber();
	y = rand->getNextNumber();
	z = 0;

	rand->setRange(0, 100);
	life = rand->getNextNumber();

	rand->setRange(0, 25.0f / 255);
	r = rand->getNextNumber();
	g = rand->getNextNumber();
	b = rand->getNextNumber();
	a = rand->getNextNumber();

	rand->setRange(20.0f / 360, 120.0f / 360);
	rx = rand->getNextNumber();
	ry = rand->getNextNumber();
	rz = rand->getNextNumber();

	ParticleNode* node = new ParticleNode();
	AUTO_RELEASE_OBJECT(node);
	node->setColor(0, 0, 0, 0);
	node->setVolume(200, 200);
	node->setColorAcceleration(r, g, b, a);
	node->setLifeTime(life);
	node->setSpeedAcceleration(x, y, z);
	node->setAngleAcceleration(rx, ry, rz);

	return node;
}

void CtrlParticleSystem::onParticleEndHandler()
{
	ParticleNode* node = createParticle();
	if (node)
	{
		this->addChild(node);
	}
}
