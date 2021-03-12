#include "PariticleNode.h"
#include "Common/Action/import.h"

render::PariticleNode::PariticleNode()
{

}

render::PariticleNode::~PariticleNode()
{
}

bool render::PariticleNode::init()
{
	if (!Node::init())
	{
		return false;
	}

	addNotifyListener(NodeNotifyType::GEOMETRY, [this]() {
		this->updateParticleParameter();
	});

	scheduleUpdate();

	return true;
}

void render::PariticleNode::resetPassedTime()
{
	_passedTime = 0;
}

float render::PariticleNode::getPassedTime() const
{
	return _passedTime;
}

void render::PariticleNode::onPariticleChange()
{
	this->notify(NodeNotifyType::GEOMETRY);
}

void render::PariticleNode::updateParticleParameter()
{

}

void render::PariticleNode::updatePariticle(float dt)
{
	
}

void render::PariticleNode::update(float dt)
{
	_deltaTime = dt;
	_passedTime += dt;
	this->updatePariticle(dt);
}

