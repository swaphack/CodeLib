#include "TestTextureNode.h"
#include "../Env/Utility.h"
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
	DrawTexture2D* pFrame = CREATE_NODE(DrawTexture2D);
	pFrame->setPosition(0, 0);
	pFrame->setAnchorPoint(0, 0);
	pFrame->setVolume(300, 300);
	Utility::loadShaderVF(pFrame, "Shader/texture/multi_texture.vs", "Shader/texture/multi_texture.fs");

	pFrame->setAmbientTexture("Resource/Image/1.jpg");
	pFrame->setDiffuseTexture("Resource/Image/NeHe.png");

	this->addChild(pFrame);
}

