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


	_scheduler->setTarget(this);
	//_scheduler->setHandler(this, SCHEDULER_DELEGATE_SCHEDULER(PariticleNode::updatePariticle));
	_scheduler->setHandler([this](float dt) {
		this->updatePariticle(dt);
	});

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

void render::PariticleNode::registerScheduler()
{
	this->unregisterScheduler();

	this->getActionProxy()->runAction(getScheduler());
}

void render::PariticleNode::unregisterScheduler()
{
	this->getActionProxy()->stopAction(getScheduler());
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
	_deltaTime = dt;
	_passedTime += dt;
	this->update(dt);
}

void render::PariticleNode::update(float dt)
{

}

