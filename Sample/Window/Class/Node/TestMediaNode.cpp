#include "TestMediaNode.h"

using namespace render;

TestMediaNode::TestMediaNode()
{

}

TestMediaNode::~TestMediaNode()
{

}

void TestMediaNode::testFunc()
{
	testMedia();
}

void TestMediaNode::testMedia()
{
	std::string url2 = "Resource/Video/1.flv";
	CtrlMedia* pMedia = CREATE_NODE(CtrlMedia);
	pMedia->loadFromURL(url2);
	pMedia->setVolume(512, 384);
	pMedia->setPosition(0, 0);
	pMedia->setAnchorPoint(0.0f, 0.0f);
	pMedia->start();
	this->addChild(pMedia);
}

