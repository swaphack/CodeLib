#include "TestEnvironmentNode.h"
#include "Utility.h"

using namespace render;
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
	pSkyBox->setFaceImage(CubeFace::LEFT, "Resource/skybox/left.jpg");
	pSkyBox->setFaceImage(CubeFace::RIGHT, "Resource/skybox/right.jpg");
	pSkyBox->setFaceImage(CubeFace::FRONT, "Resource/skybox/front.jpg");
	pSkyBox->setFaceImage(CubeFace::BACK, "Resource/skybox/back.jpg");
	pSkyBox->setFaceImage(CubeFace::TOP, "Resource/skybox/top.jpg");
	pSkyBox->setFaceImage(CubeFace::BOTTOM, "Resource/skybox/bottom.jpg");

	pSkyBox->setVolume(1, 1, 1);
	pSkyBox->setPosition(0, 0, 0);
	pSkyBox->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pSkyBox);

	Utility::loadShader(pSkyBox->getMaterials(), "Shader/skybox_vertex.glsl", "Shader/skybox_fragment.glsl");
}
