#include "TestPostProcessing.h"
#include "Utility.h"

TestPostProcessing::TestPostProcessing()
{

}

TestPostProcessing::~TestPostProcessing()
{

}

void TestPostProcessing::initNodes()
{
	this->testImage();

	this->testSimplePostProcessing();
}

void TestPostProcessing::testSimplePostProcessing()
{
	render::PostProcessingNode* pNode = CREATE_NODE(render::PostProcessingNode);
	pNode->setAnchorPoint(0, 0);
	pNode->setPosition(0, 0);
	pNode->setVolume(512,384);

	pNode->addChild(createImage());

	this->addChild(pNode);

	Utility::loadShader(pNode, "Shader/frame/simple_frame_buffer.vs", "Shader/frame/simple_frame_buffer.fs");
}

void TestPostProcessing::testImage()
{
	auto frameSize = render::Canvas::getInstance()->getView()->getFrameSize();

	std::string filepath = "Resource/Image/world_texture.jpg";

	render::CtrlImage* pImage = CREATE_NODE(render::CtrlImage);
	pImage->setImagePath(filepath);
	pImage->setAnchorPoint(math::Vector2());
	pImage->setVolume(frameSize);

	this->addChild(pImage);
}

render::CtrlImage* TestPostProcessing::createImage()
{
	auto frameSize = render::Canvas::getInstance()->getView()->getFrameSize();

	std::string filepath = "Resource/Image/world.jpg";

	render::CtrlImage* pImage = CREATE_NODE(render::CtrlImage);
	pImage->setImagePath(filepath);
	pImage->setAnchorPoint(math::Vector2());
	pImage->setVolume(frameSize);

	return pImage;
}

