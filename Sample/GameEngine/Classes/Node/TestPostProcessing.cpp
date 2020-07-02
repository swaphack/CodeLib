#include "TestPostProcessing.h"
#include "Utility.h"
#include "system.h"

TestPostProcessing::TestPostProcessing()
{

}

TestPostProcessing::~TestPostProcessing()
{

}

void TestPostProcessing::initNodes()
{
	this->testImage();

	this->testPixelPostProcessing();

	//testFramePostProcessing();
}

void TestPostProcessing::testFramePostProcessing()
{
	auto frameSize = render::Canvas::getInstance()->getView()->getFrameSize();

	std::string filepath = "Resource/Image/world.jpg";

	render::CtrlImage* pImage = CREATE_NODE(render::CtrlImage);
	pImage->setImagePath(filepath);
	pImage->setAnchorPoint(math::Vector2());
	pImage->setVolume(512, 384);
	Utility::loadShader(pImage, "Shader/texture/texture.vs", "Shader/texture/texture.fs");

	render::FramePostProcessingNode* pNode = CREATE_NODE(render::FramePostProcessingNode);
	pNode->setAnchorPoint(0, 0);
	pNode->setPosition(200, 100);
	pNode->setVolume(512,384);
	Utility::loadShader(pNode, "Shader/frame/simple_frame_buffer.vs", "Shader/frame/simple_frame_buffer.fs");

	pNode->addChild(pImage);
	this->addChild(pNode);
}

void TestPostProcessing::testPixelPostProcessing()
{
	const auto& frameSize = render::Tool::getGLViewSize();

	render::PixelPostProcessingNode* pNode = CREATE_NODE(render::PixelPostProcessingNode);

	pNode->setAnchorPoint(0, 0);
	pNode->setPosition(0, 0);
	pNode->setVolume(frameSize.getWidth(), frameSize.getHeight());
	Utility::loadShader(pNode, "Shader/frame/simple_frame_buffer.vs", "Shader/frame/simple_frame_buffer.fs");
	this->addChild(pNode);
}

void TestPostProcessing::testImage()
{
	const auto& frameSize = render::Tool::getGLViewSize();

	std::string filepath = "Resource/Image/world_texture.jpg";

	render::CtrlImage* pImage = CREATE_NODE(render::CtrlImage);
	pImage->setImagePath(filepath);
	pImage->setAnchorPoint(math::Vector2());
	pImage->setVolume(frameSize.getWidth(), frameSize.getHeight());
	Utility::loadShader(pImage, "Shader/texture/texture.vs", "Shader/texture/texture.fs");

	this->addChild(pImage);
}
