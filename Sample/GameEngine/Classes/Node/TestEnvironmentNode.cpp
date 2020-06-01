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
	this->init3DSkyBox();
	//this->testImageShader();

	this->testCubeMap();
}

void TestEnvironmentNode::init3DSkyBox()
{
	render::SkyBox* pSkyBox = CREATE_NODE(render::SkyBox);
	pSkyBox->setFaceImage(CubeFace::LEFT, "Resource/skybox/right.jpg");
	pSkyBox->setFaceImage(CubeFace::RIGHT, "Resource/skybox/left.jpg");
	pSkyBox->setFaceImage(CubeFace::FRONT, "Resource/skybox/front.jpg");
	pSkyBox->setFaceImage(CubeFace::BACK, "Resource/skybox/back.jpg");
	pSkyBox->setFaceImage(CubeFace::TOP, "Resource/skybox/top.jpg");
	pSkyBox->setFaceImage(CubeFace::BOTTOM, "Resource/skybox/bottom.jpg");

	//pSkyBox->setScale(2);
	pSkyBox->setRotation(0, 0, 180);
	pSkyBox->setVolume(2048, 2048, 2048);
	pSkyBox->setPosition(512, 384, 0);
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

	pSkyBox->getActionProxy()->runAction(pRepeateAction);

}

void TestEnvironmentNode::init2DSkyBox()
{
	render::MultiFaceCube* pSkyBox = CREATE_NODE(render::MultiFaceCube);
	pSkyBox->setFaceImage(CubeFace::LEFT, "Resource/skybox/right.jpg");
	pSkyBox->setFaceImage(CubeFace::RIGHT, "Resource/skybox/left.jpg");
	pSkyBox->setFaceImage(CubeFace::FRONT, "Resource/skybox/front.jpg");
	pSkyBox->setFaceImage(CubeFace::BACK, "Resource/skybox/back.jpg");
	pSkyBox->setFaceImage(CubeFace::TOP, "Resource/skybox/top.jpg");
	pSkyBox->setFaceImage(CubeFace::BOTTOM, "Resource/skybox/bottom.jpg");

	//pSkyBox->setScale(0.25f);
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

void TestEnvironmentNode::testCubeMap()
{
	render::CubeMap* pCubMap = CREATE_NODE(render::CubeMap);
	pCubMap->setFaceImage(CubeFace::LEFT, "Resource/skybox/right.jpg");
	pCubMap->setFaceImage(CubeFace::RIGHT, "Resource/skybox/left.jpg");
	pCubMap->setFaceImage(CubeFace::FRONT, "Resource/skybox/front.jpg");
	pCubMap->setFaceImage(CubeFace::BACK, "Resource/skybox/back.jpg");
	pCubMap->setFaceImage(CubeFace::TOP, "Resource/skybox/top.jpg");
	pCubMap->setFaceImage(CubeFace::BOTTOM, "Resource/skybox/bottom.jpg");

	//pSkyBox->setScale(0.25f);
	pCubMap->setVolume(512, 384, 512);
	pCubMap->setPosition(512, 384, 100);
	pCubMap->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pCubMap);

	Utility::loadShader(pCubMap->getMaterials(), "Shader/cubemap.vs", "Shader/cubemap.fs");

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(0, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pCubMap->getActionProxy()->runAction(pRepeateAction);
}

void TestEnvironmentNode::testImageShader()
{
	auto frameSize = Canvas::getInstance()->getView()->getFrameSize();

	std::string filepath = "Resource/Image/world.jpg";

	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath(filepath);
	pImage->setAnchorPoint(math::Vector2(0.5f, 0.5f));
	pImage->setVolume(800, 600);
	pImage->setPosition(math::Vector2(512, 384));
	this->addChild(pImage);

	Utility::updateNodeShader(pImage);
}
