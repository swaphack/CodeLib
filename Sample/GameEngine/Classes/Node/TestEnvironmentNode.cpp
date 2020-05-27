#include "TestFragmentNode.h"
#include "Utility.h"

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
	MultiFaceCube* pCube = CREATE_NODE(MultiFaceCube);
	pCube->addMaterialTexture("Face", pTexture2D);
	pCube->setVolume(200, 300, 200);
	pCube->setAllMaterialsTexture("Face");
	pCube->setRotation(45, 45, 0);
	pCube->setPosition(400, 400);
	Utility::updateNodeShader(pCube);

	FragmentBlend* pBlend = pCube->getFragOperator()->getHandle<FragmentBlend>();
	pBlend->setEnabled(true);
	pBlend->setBlendColor(sys::Color4F(0.25f, 0.25f, 0, 1.0f));
	pBlend->setBlendFactor(BlendingFactorSrc::SRC_ALPHA, BlendingFactorDest::DST_COLOR);

	this->addChild(pCube);
}
