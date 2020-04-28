#include "ShaderScene.h"
#include "mathlib.h"

using namespace render;
using namespace math;

ShaderScene::ShaderScene()
{

}

ShaderScene::~ShaderScene()
{

}

bool ShaderScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	this->testColorShader();

	return true;
}

void ShaderScene::testColorShader()
{
	auto frameSize = Canvas::getInstance()->getView()->getFrameSize();

	std::string filepath = "Resource/Image/world.jpg";

	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath(filepath);
	pImage->setAnchorPoint(Vector2());
	pImage->setVolume(frameSize);
	this->addChild(pImage);


	std::string vPath = "Resource/shader/shader_v_1.glsl";
	std::string fPath = "Resource/shader/shader_f_1.glsl";

	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->load(vPath, fPath);


	GLDebug::showError();
	pProgram->link();


	GLDebug::showError();

	auto pBlock = pProgram->getUniformBlock("Uniforms");
	if (pBlock)
	{
		pBlock->initUniformBlock();
	}
}

