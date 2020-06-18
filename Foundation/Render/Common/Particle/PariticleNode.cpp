#include "PariticleNode.h"
#include "Common/Action/import.h"

render::PariticleNode::PariticleNode()
{

}

render::PariticleNode::~PariticleNode()
{
	SAFE_DELETE(_scheduler);
}

bool render::PariticleNode::init()
{
	if (!Node::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::PARTICLE, [this]() {
		this->updateParticleParameter();
	});

	//_scheduler = new Scheduler();
	//_scheduler->setHandler(this, SCHEDULER_DELEGATE_SCHEDULER(PariticleNode::updatePariticle));
	//this->getActionProxy()->runAction(_scheduler);

	return true;
}

float render::PariticleNode::getDelta() const
{
	return _delta;
}

void render::PariticleNode::onPariticleChange()
{
	this->notify(NodeNotifyType::PARTICLE);
}

void render::PariticleNode::updateParticleParameter()
{

}

void render::PariticleNode::updatePariticle(float dt)
{
	_delta = dt;
	this->updateTime(dt);
}

void render::PariticleNode::updateTime(float dt)
{

}

