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
	pMedia->setMediaURL(url2);
	pMedia->setAnchorPoint(0.0f, 0.0f);
	pMedia->start();
	this->addChild(pMedia);
}

