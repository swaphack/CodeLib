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
	Texture2D* pTexture2D = G_TEXTURE_CACHE->createTexture2D("Resource/Image/NeHe.png");
	CubeModel* pCube = CREATE_NODE(CubeModel);
	pCube->addTexture("Face", pTexture2D);
	pCube->setVolume(200, 300, 200);
	pCube->setAllFacesTexture("Face");
	pCube->setRotation(45, 45, 0);
	pCube->setPosition(400, 400);
	ShaderUtility::updateNodeShader(pCube);

	FragmentBlend* pBlend = pCube->getFragOperator()->getHandle<FragmentBlend>();
	pBlend->setEnabled(true);
	pBlend->setBlendColor(sys::Color4F(0.25f, 0.25f, 0, 1.0f));
	pBlend->setBlendFactor(BlendingFactorSrc::SRC_ALPHA, BlendingFactorDest::DST_COLOR);
	


	this->addChild(pCube);
}
