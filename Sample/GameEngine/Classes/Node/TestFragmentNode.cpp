#include "TestFragmentNode.h"
#include "ShaderUtility.h"

using namespace render;

TestFragmentNode::TestFragmentNode()
{
}

TestFragmentNode::~TestFragmentNode()
{
}

void TestFragmentNode::testFunc()
{
	this->testStencil();
}

void TestFragmentNode::testStencil()
{	
	Stencil* pStencil = CREATE_NODE(Stencil);
	pStencil->setVolume(400, 400, 400);
	this->addChild(pStencil);

	Texture2D* texture2D = G_TEXTURE_CACHE->createTexture2D("Resource/Image/NeHe.png");
	CubeModel* pCube = CREATE_NODE(CubeModel);
	pCube->addTexture("Face", texture2D);
	pCube->setVolume(200, 300, 200);
	pCube->setColor(sys::Color3B(255, 255, 255));
	pCube->setAllFacesTexture("Face");
	pCube->setRotation(45, 45, 0);
	pCube->setPosition(400, 400);
	ShaderUtility::updateNodeShader(pCube, false);

	pStencil->setStencilNode(pCube);
	
	texture2D = G_TEXTURE_CACHE->createTexture2D("Resource/Image/sqi.png");
	
	pCube = CREATE_NODE(CubeModel);
	pCube->addTexture("Face", texture2D);
	pCube->setVolume(200, 300, 200);
	pCube->setRotation(-45, -45, 0);
	pCube->setAllFacesTexture("Face");
	pCube->setPosition(400, 400);
	ShaderUtility::updateNodeShader(pCube);

	pStencil->addChild(pCube);
}
