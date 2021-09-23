#include "TestPostProcessing.h"
#include "../Env/Utility.h"
#include "system.h"
#include "ui.h"

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

	testFramePostProcessing();
}

void TestPostProcessing::testFramePostProcessing()
{
	auto frameSize = render::Tool::getViewSize();

	std::string filepath = "Resource/Image/world.jpg";

	ui::CtrlImage* pImage = CREATE_NODE(ui::CtrlImage);
	pImage->setImagePath(filepath);
	pImage->setAnchorPoint(0, 0);
	pImage->setPosition(100, 100);
	pImage->setVolume(512, 384);
	Utility::loadShaderVF(pImage, "Shader/texture/texture.vs", "Shader/texture/texture.fs");

	render::PostProcessingNode* pNode = CREATE_NODE(render::PostProcessingNode);
	pNode->setAnchorPoint(0.0f, 0.0f);
	pNode->setPosition(100, 100);
	pNode->setVolume(924, 668);
	Utility::loadShaderVF(pNode, "Shader/frame/simple_frame_buffer.vs", "Shader/frame/simple_frame_buffer.fs");

	pNode->addChild(pImage);
	this->addChild(pNode);
}

void TestPostProcessing::testPixelPostProcessing()
{
	const auto& frameSize = render::Tool::getViewSize();

	render::PixelPostProcessingNode* pNode = CREATE_NODE(render::PixelPostProcessingNode);

	pNode->setAnchorPoint(0, 0);
	pNode->setPosition(0, 0);
	pNode->setVolume(frameSize.getWidth(), frameSize.getHeight());
	Utility::loadShaderVF(pNode, "Shader/frame/simple_frame_buffer.vs", "Shader/frame/simple_frame_buffer.fs");
	this->addChild(pNode);
}

void TestPostProcessing::testImage()
{
	const auto& frameSize = render::Tool::getViewSize();

	std::string filepath = "Resource/Image/world_texture.jpg";

	ui::CtrlImage* pImage = CREATE_NODE(ui::CtrlImage);
	pImage->setImagePath(filepath);
	pImage->setAnchorPoint(math::Vector2());
	pImage->setVolume(frameSize.getWidth(), frameSize.getHeight());
	Utility::loadShaderVF(pImage, "Shader/texture/texture.vs", "Shader/texture/texture.fs");

	this->addChild(pImage);
}
