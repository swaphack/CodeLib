#include "TestFragmentNode.h"
#include "Utility.h"

using namespace render;

TestFragmentNode::TestFragmentNode()
{
}

TestFragmentNode::~TestFragmentNode()
{
}

void TestFragmentNode::initNodes()
{
	this->testStencil();
}

void TestFragmentNode::testStencil()
{
	MultiFaceCube* pCube = CREATE_NODE(MultiFaceCube);
	pCube->setTexture("Resource/Image/NeHe.png");
	pCube->setRotation(45, 45, 0);
	pCube->setPosition(400, 400);
	Utility::loadDefaultShader(pCube);

	FragmentBlend* pBlend = pCube->getFragOperator()->getHandle<FragmentBlend>();
	pBlend->setEnabled(true);
	pBlend->setBlendColor(phy::Color4B(0.25f, 0.25f, 0, 1.0f));
	pBlend->setBlendFactor(BlendingFactorSrc::SRC_ALPHA, BlendingFactorDest::DST_COLOR);

	this->addChild(pCube);
}
