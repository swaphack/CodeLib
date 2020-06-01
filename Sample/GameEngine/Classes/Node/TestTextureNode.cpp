#include "TestTextureNode.h"
#include "Utility.h"
using namespace render;

TestTextureNode::TestTextureNode()
{

}

TestTextureNode::~TestTextureNode()
{

}

void TestTextureNode::testFunc()
{
	this->testMultiTexture();
}

void TestTextureNode::testMultiTexture()
{
	CtrlFrame* pFrame = CREATE_NODE(CtrlFrame);
	pFrame->setPosition(0, 0);
	pFrame->setAnchorPoint(0, 0);
	pFrame->setVolume(300, 300);
	Utility::loadShader(pFrame->getMaterials(), "Shader/multi_texture.vs", "Shader/multi_texture.fs");
	Utility::initShaderAttrib(pFrame->getMaterials());

	pFrame->getMaterials()->addTexture("texture0", "Resource/Image/1.jpg");
	pFrame->getMaterials()->addTexture("texture1", "Resource/Image/NeHe.png");

	pFrame->getMaterial()->getMaterialDetail()->setAmbientTextureMap("texture0");
	pFrame->getMaterial()->getMaterialDetail()->setDiffuseTextureMap("texture1");

	this->addChild(pFrame);
}

