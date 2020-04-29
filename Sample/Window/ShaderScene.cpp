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

	this->testShader1();

	return true;
}

void ShaderScene::testShader1()
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

	auto pUniformBlock = pProgram->getUniformBlock("Uniforms");
	if (pUniformBlock == nullptr)
	{
		return;
	}

	ShaderUniformBlockData blockData;
	if (pUniformBlock->getBlockData(blockData))
	{
		float scale = 0.5;
		float translation[] = { 0.1f, 0.1f, 0.0f };
		float rotation[] = { 90, 0.0f, 0.0f, 1.0f };
		uint8_t enabled = GL_TRUE;

		blockData.setValue("scale", &scale);
		blockData.setValue("translation", &translation);
		blockData.setValue("rotation", &rotation);
		blockData.setValue("enabled", &enabled);

		BufferObject* pObject = CREATE_OBJECT(BufferObject);
		pObject->setBufferTarget(BufferTarget::UNIFORM_BUFFER);
		pObject->setBufferData(blockData.getBlockData().getSize(), blockData.getBlockData().getValue(), BufferDataUsage::STATIC_DRAW);

		GLDebug::showError();
	}
}

