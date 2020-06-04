#include "TestPostProcessing.h"
#include "Utility.h"

TestPostProcessing::TestPostProcessing()
{

}

TestPostProcessing::~TestPostProcessing()
{

}

void TestPostProcessing::testFunc()
{
	this->testSimplePostProcessing();
}

void TestPostProcessing::testSimplePostProcessing()
{
	render::PostProcessingNode* pNode = CREATE_NODE(render::PostProcessingNode);
	pNode->setAnchorPoint(0, 0);
	pNode->setPosition(0, 0);
	pNode->setVolume(render::Tool::getGLViewSize());

	this->addChild(pNode);

	Utility::loadShader(pNode->getMaterials(), "Shader/simple_frame_buffer.vs", "Shader/simple_frame_buffer.fs");

	render::PostProcessing::getInstance()->setPostProcessingNode(pNode);
}

