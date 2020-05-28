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

	pSkyBox->setScale(1000000);
	pSkyBox->setVolume(400, 400, 400);
	pSkyBox->setPosition(512, 384, 0);
	pSkyBox->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pSkyBox);

	Utility::loadShader(pSkyBox->getMaterials(), "Shader/skybox_vertex.glsl", "Shader/skybox_fragment.glsl");
	Utility::runRotateAction(pSkyBox);

	pSkyBox->setAllShaderProgramFunc([](ShaderProgram* program) {
		auto pUniform = program->getUniform("viewMatrix");
		if (pUniform)
		{
			math::Matrix44 viewMat = Camera::getMainCamera()->getViewMatrix();
			math::Matrix44 Mat = math::Matrix33(viewMat);
			pUniform->setMatrix4(Mat);
		}
	});
}
