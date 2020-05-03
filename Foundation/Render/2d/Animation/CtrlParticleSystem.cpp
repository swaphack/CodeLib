#include "CtrlParticleSystem.h"
#include "system.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"
#include "Common/Tool/TextureTool.h"
using namespace render;

ParticleNode::ParticleNode()
{

}

ParticleNode::~ParticleNode()
{

}

void ParticleNode::drawSample()
{
	GLState::enable(EnableModel::TEXTURE_2D);
	GLTexture::bindTexture2D(0);

	GLClientArrays::enableClientState(ClientArrayType::VERTEX_ARRAY);
	GLClientArrays::setVertexPointer(3, DataType::FLOAT, 0, _texRect.vertices);

	GLClientArrays::enableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
	GLClientArrays::setTexCoordPointer(2, DataType::FLOAT, 0, _texRect.uvs);

	GLClientArrays::enableClientState(ClientArrayType::COLOR_ARRAY);
	GLClientArrays::setColorPointer(4, DataType::FLOAT, 0, _texRect.colors);

	GLClientArrays::drawElements(DrawMode::TRIANGLES, 6, IndexDataType::UNSIGNED_SHORT, _texRect.indices);

	GLClientArrays::disableClientState(ClientArrayType::VERTEX_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::COLOR_ARRAY);

	GLState::disable(EnableModel::TEXTURE_2D);
}

void ParticleNode::update(float interval)
{
	if (_lifeTime <= 0)
	{
		return;
	}

	_lifeTime -= interval;

	_colorInit.add(_colorAcceleration);
	_position += _speedAcceleration;
	_scale += _scaleAcceleration;
	_rotation += _angleAcceleration;

	convertColor4FTo4B(_colorInit, _color);
	TextureTool::setTexture2DVertexts(&_texRect, math::Vector3(), _volume, _anchor);

	Tool::convertToOGLPoisition(_position, _obPosition);
}
/*
void ParticleNode::notifyEvents()
{
	ColorNode::notifyEvents();

	convertColor4BTo4F(_color, _colorInit);

	math::Size size = math::Size(_volume.getWidth(), _volume.getHeight());
	math::Rect rect = math::Rect(0, 0, _volume.getWidth(), _volume.getHeight());

	TextureTool::setTexture2DCoords(&_texRect, size, rect);
	TextureTool::setTexture2DVertexts(&_texRect, math::Vector3(), _volume, _anchor);
}
*/
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

void CtrlParticleSystem::setCount(uint32_t count)
{
	if (_particleCount == count) 
	{
		return;
	}
	this->removeAllChildren();

	_particleCount = count;

	// for test
	for (uint32_t i = 0; i < count; i++)
	{
		ParticleNode* node = createParticle();
		if (node)
		{
			this->addChild(node);
		}
	}
}

uint32_t CtrlParticleSystem::getCount()
{
	return _particleCount;
}

void CtrlParticleSystem::updateSelf(float interval)
{
	std::vector<ParticleNode*> removeNodes;

	auto it = _children.begin();
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

	x = sys::Random::getNumber(0.0f, 2.0f);
	y = sys::Random::getNumber(0.0f, 2.0f);
	z = 0;

	life = sys::Random::getNumber(0.0f, 100.0f);

	r = sys::Random::getNumber(0.0f, 25.0f / 255);
	g = sys::Random::getNumber(0.0f, 25.0f / 255);
	b = sys::Random::getNumber(0.0f, 25.0f / 255);
	a = sys::Random::getNumber(0.0f, 25.0f / 255);

	rx = sys::Random::getNumber(20.0f / 360, 120.0f / 360);
	ry = sys::Random::getNumber(20.0f / 360, 120.0f / 360);
	rz = sys::Random::getNumber(20.0f / 360, 120.0f / 360);

	ParticleNode* node = CREATE_NODE(ParticleNode);
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
