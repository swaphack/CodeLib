#include "TestEnvironmentNode.h"
#include "Utility.h"

TestEnvironmentNode::TestEnvironmentNode()
{
}

TestEnvironmentNode::~TestEnvironmentNode()
{
}

void TestEnvironmentNode::testFunc()
{
	this->initSkyBox();
}

void TestEnvironmentNode::initSkyBox()
{
	render::SkyBox* pSkyBox = CREATE_NODE(render::SkyBox);
	pSkyBox->setAllFacesImage("Resource/Image/NeHe.png");

	pSkyBox->setVolume(1, 1, 1);
	pSkyBox->setPosition(0, 0, 0);
	pSkyBox->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pSkyBox);

	Utility::loadShader(pSkyBox->getMaterials(), "Shader/skybox_vertex.glsl", "Shader/skybox_fragment.glsl");
}
