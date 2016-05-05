#include "CtrlParticleSystem.h"
#include "system.h"
using namespace render;

ParticleNode::ParticleNode()
:_liftTime(0)
{

}

ParticleNode::~ParticleNode()
{

}

void ParticleNode::draw()
{
	Node::draw();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GLTool::setColor(getColor());

	GLTool::drawTriangleVertex(&_texRect);

	glDisable(GL_BLEND);
}

void ParticleNode::setSpeedAcceleration(float x, float y, float z)
{
	_speedAcceleration.x = x;
	_speedAcceleration.y = y;
	_speedAcceleration.z = z;
}

sys::Vector ParticleNode::getSpeedAccelertaion()
{
	return _speedAcceleration;
}

void ParticleNode::setColorAcceleration(float red, float green, float blue, float alpha)
{
	_colorAcceleration.red = red;
	_colorAcceleration.green = green;
	_colorAcceleration.blue = blue;
	_colorAcceleration.alpha = alpha;
}

sys::Color4F ParticleNode::getColorAcceleration()
{
	return _colorAcceleration;
}

void ParticleNode::setLifeTime(float time)
{
	_liftTime = time;
}

float ParticleNode::getLifeTime()
{
	return _liftTime;
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

	convertColor4FTo4B(_colorInit, _color);
	TextureTool::setTexture2DVertexts(&_texRect, _position, _volume, _anchor);
}

void ParticleNode::initSelf()
{
	ColorNode::initSelf();

	convertColor4BTo4F(_color, _colorInit);

	sys::Size size = sys::Size(_volume.width, _volume.height);
	sys::Rect rect = sys::Rect(0, 0, _volume.width, _volume.height);
	TextureTool::setTexture2DCoords(&_texRect, size, rect);
	TextureTool::setTexture2DVertexts(&_texRect, _position, _volume, _anchor);
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
	// for test
	for (uint i = 0; i < _particleCount; i++)
	{
		ParticleNode* node = createParticle();
		if (node)
		{
			this->addChild(node);
		}
	}
	
	return true;
}

void CtrlParticleSystem::setCount(uint count)
{
	_particleCount = count;
}

uint CtrlParticleSystem::getCount()
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

	ParticleNode* node = new ParticleNode();
	AUTO_RELEASE_OBJECT(node);
	node->setColor(0, 0, 0, 0);
	node->setVolume(5, 5, 0);
	node->setColorAcceleration(r, g, b, a);
	node->setLifeTime(life);
	node->setSpeedAcceleration(x, y, z);

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
