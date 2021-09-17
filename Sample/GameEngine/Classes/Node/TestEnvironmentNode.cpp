#include "TestEnvironmentNode.h"
#include "Utility.h"

using namespace render;
TestEnvironmentNode::TestEnvironmentNode()
{
}

TestEnvironmentNode::~TestEnvironmentNode()
{
}

void TestEnvironmentNode::initNodes()
{
	//this->addGrid();

	this->init3DSkyBox();

	//this->testMatrix();
}

void TestEnvironmentNode::init3DSkyBox()
{
	render::SkyBox* pSkyBox = CREATE_NODE(render::SkyBox);
	pSkyBox->setLeftTexture("Resource/skybox/left.jpg");
	pSkyBox->setRightTexture("Resource/skybox/right.jpg");
	pSkyBox->setFrontTexture("Resource/skybox/front.jpg");
	pSkyBox->setBackTexture("Resource/skybox/back.jpg");
	pSkyBox->setTopTexture("Resource/skybox/top.jpg");
	pSkyBox->setBottomTexture("Resource/skybox/bottom.jpg");

	pSkyBox->setScale(100.0f);
	pSkyBox->setVolume(2048, 2048, 2048);
	pSkyBox->setPosition(512, 384, 0);
	pSkyBox->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pSkyBox);

	Utility::loadShaderVF(pSkyBox, "Shader/env/skybox.vs", "Shader/env/skybox.fs");
	/*
	pSkyBox->setShaderProgramFunc([pSkyBox](ShaderProgram* program) {
		auto pUniform = program->getUniform("matrix.view");
		if (pUniform)
		{
			math::Matrix4x4 viewMat = pSkyBox->getCamera()->getViewMatrix();
			math::Matrix4x4 mat = math::Matrix3x3(viewMat);
			pUniform->setMatrix4x4(mat);
		}
	});
	*/
}

void TestEnvironmentNode::init2DSkyBox()
{
	render::MultiFaceCube* pSkyBox = CREATE_NODE(render::MultiFaceCube);
	pSkyBox->setFaceTexture(CubeFace::LEFT, "Resource/skybox/left.jpg");
	pSkyBox->setFaceTexture(CubeFace::RIGHT, "Resource/skybox/right.jpg");
	pSkyBox->setFaceTexture(CubeFace::FRONT, "Resource/skybox/front.jpg");
	pSkyBox->setFaceTexture(CubeFace::BACK, "Resource/skybox/back.jpg");
	pSkyBox->setFaceTexture(CubeFace::TOP, "Resource/skybox/top.jpg");
	pSkyBox->setFaceTexture(CubeFace::BOTTOM, "Resource/skybox/bottom.jpg");

	pSkyBox->setScale(0.25f);
	pSkyBox->setVolume(2048, 2048, 2048);
	pSkyBox->setPosition(512, 384, 0);
	pSkyBox->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pSkyBox);

	Utility::loadShaderVF(pSkyBox, "Shader/texture/texture.vs", "Shader/texture/texture.fs");

	pSkyBox->setShaderProgramFunc([pSkyBox](ShaderProgram* program) {
		auto pUniform = program->getUniform("matrix.view");
		if (pUniform)
		{
			math::Matrix4x4 viewMat = pSkyBox->getCamera()->getViewMatrix();
			math::Matrix4x4 Mat = math::Matrix3x3(viewMat);
			pUniform->setMatrix4x4(Mat);
		}
	});

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setDifferentRotation(0, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pSkyBox->getActionProxy()->runAction(pRepeateAction);
}

void TestEnvironmentNode::addGrid()
{
	render::Grid* pGrid = CREATE_NODE(render::Grid);
	pGrid->setAnchorPoint(0.5f, 0.5f, 0.5f);
	pGrid->setVolume(10240, 0, 10240);
	pGrid->setGridWidth(100);
	pGrid->setPosition(512, 384);
	if (pGrid->getCamera()->getDimensions() == DimensionsType::TWO)
	{
		pGrid->setRotationX(90);
	}

	Utility::loadShaderVGF(pGrid, "Shader/geometry/draw_line.vs", "Shader/geometry/draw_line.gs", "Shader/geometry/draw_line.fs");

	this->addChild(pGrid);
}

void TestEnvironmentNode::testMatrix()
{
	math::Vector3 rotate(0, 90, 0);

	math::Vector3 radian = Tool::convertToRadian(rotate);

	math::Matrix4x4 mat;
	mat.setRotate(radian);

	math::Vector3 up(0, 0, 1);

	math::Vector3 result = math::Matrix4x4::transpose(up, mat);

	int a = 1;
}

void TestEnvironmentNode::testMultiPort()
{
	math::Size size = Canvas::getInstance()->getView()->getViewSize();
	Canvas::getInstance()->setViewPort(0, 0, size.getWidth() * 0.5f, size.getHeight() * 0.5f);
}
