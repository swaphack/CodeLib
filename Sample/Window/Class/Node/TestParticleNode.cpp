#include "TestParticleNode.h"

using namespace render;

TestParticleNode::TestParticleNode()
{

}

TestParticleNode::~TestParticleNode()
{

}

void TestParticleNode::testFunc()
{

}

void TestParticleNode::testParticle()
{
	CtrlParticleSystem* node = CREATE_NODE(CtrlParticleSystem);
	node->setPosition(512, 386, 0);
	node->setCount(100);
	node->setScale(2, 1, 1);
	node->start();
	this->addChild(node);
}

