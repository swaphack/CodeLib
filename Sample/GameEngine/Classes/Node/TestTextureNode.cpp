#include "TestTextureNode.h"
#include "Utility.h"
using namespace render;

TestTextureNode::TestTextureNode()
{

}

TestTextureNode::~TestTextureNode()
{

}

void TestTextureNode::initNodes()
{
	this->testMultiTexture();
}

void TestTextureNode::testMultiTexture()
{
	CtrlFrame* pFrame = CREATE_NODE(CtrlFrame);
	pFrame->setPosition(0, 0);
	pFrame->setAnchorPoint(0, 0);
	pFrame->setVolume(300, 300);
	Utility::loadShader(pFrame, "Shader/texture/multi_texture.vs", "Shader/texture/multi_texture.fs");
	Utility::initShaderAttrib(pFrame);

	pFrame->setAmbientTexture("Resource/Image/1.jpg");
	pFrame->setDiffuseTexture("Resource/Image/NeHe.png");

	this->addChild(pFrame);
}

