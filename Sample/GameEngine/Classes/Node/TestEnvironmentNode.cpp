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
	this->testCamera();
}

void TestEnvironmentNode::init3DSkyBox()
{
	render::SkyBox* pSkyBox = CREATE_NODE(render::SkyBox);
	pSkyBox->setFaceImage(CubeFace::LEFT, "Resource/skybox/left.jpg");
	pSkyBox->setFaceImage(CubeFace::RIGHT, "Resource/skybox/right.jpg");
	pSkyBox->setFaceImage(CubeFace::FRONT, "Resource/skybox/front.jpg");
	pSkyBox->setFaceImage(CubeFace::BACK, "Resource/skybox/back.jpg");
	pSkyBox->setFaceImage(CubeFace::TOP, "Resource/skybox/top.jpg");
	pSkyBox->setFaceImage(CubeFace::BOTTOM, "Resource/skybox/bottom.jpg");

	//pSkyBox->setScale(0.25f);
	pSkyBox->setVolume(2048, 2048, 2048);
	pSkyBox->setPosition(0, 0, 0);
	pSkyBox->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pSkyBox);

	Utility::loadShader(pSkyBox->getMaterials(), "Shader/skybox.vs", "Shader/skybox.fs");
	/*
	pSkyBox->setAllShaderProgramFunc([](ShaderProgram* program) {
		auto pUniform = program->getUniform("viewMatrix");
		if (pUniform)
		{
			math::Matrix44 viewMat = Camera::getMainCamera()->getViewMatrix();
			math::Matrix44 Mat = math::Matrix33(viewMat);
			pUniform->setMatrix4(Mat);
		}
	});
	*/

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(0, 180, 0);
	pRotateByAction->setDuration(20);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	//pSkyBox->getActionProxy()->runAction(pRepeateAction);

}

void TestEnvironmentNode::init2DSkyBox()
{
	render::MultiFaceCube* pSkyBox = CREATE_NODE(render::MultiFaceCube);
	pSkyBox->setFaceImage(CubeFace::LEFT, "Resource/skybox/left.jpg");
	pSkyBox->setFaceImage(CubeFace::RIGHT, "Resource/skybox/right.jpg");
	pSkyBox->setFaceImage(CubeFace::FRONT, "Resource/skybox/front.jpg");
	pSkyBox->setFaceImage(CubeFace::BACK, "Resource/skybox/back.jpg");
	pSkyBox->setFaceImage(CubeFace::TOP, "Resource/skybox/top.jpg");
	pSkyBox->setFaceImage(CubeFace::BOTTOM, "Resource/skybox/bottom.jpg");

	pSkyBox->setScale(0.25f);
	pSkyBox->setVolume(2048, 2048, 2048);
	pSkyBox->setPosition(512, 384, 0);
	pSkyBox->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pSkyBox);

	Utility::loadShader(pSkyBox->getMaterials(), "Shader/texture3d.vs", "Shader/texture3d.fs");

	pSkyBox->setAllShaderProgramFunc([](ShaderProgram* program) {
		auto pUniform = program->getUniform("viewMatrix");
		if (pUniform)
		{
			math::Matrix44 viewMat = Camera::getMainCamera()->getViewMatrix();
			math::Matrix44 Mat = math::Matrix33(viewMat);
			pUniform->setMatrix4(Mat);
		}
	});

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(0, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pSkyBox->getActionProxy()->runAction(pRepeateAction);
}
void TestEnvironmentNode::testCamera()
{
	Camera* pCamera = Camera::getMainCamera();

	if (pCamera->getDimensions() != CameraDimensions::THREE)
	{
		return;
	}

	pCamera->setPositionZ(10.0f);

	Action* pAction = nullptr;
	{
		RotateByAction* pAction0 = CREATE_ACTION(RotateByAction);
		pAction0->setRotation(0, 30, 0);
		pAction0->setDuration(1);

		pAction = pAction0;
	}
	
	{
		MoveByAction* pAction1 = CREATE_ACTION(MoveByAction);
		pAction1->setPosition(0, 0, 1);
		pAction1->setDuration(10);

		pAction = pAction1;
	}

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pAction);

	pCamera->getActionProxy()->runAction(pRepeateAction);
	
}
