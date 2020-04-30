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

	this->testSubroutineUniform();

	return true;
}

void ShaderScene::testImage()
{
	auto frameSize = Canvas::getInstance()->getView()->getFrameSize();

	std::string filepath = "Resource/Image/world.jpg";

	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath(filepath);
	pImage->setAnchorPoint(Vector2());
	pImage->setVolume(frameSize);
	this->addChild(pImage);
}

void ShaderScene::testShaderUniformBlock()
{
	std::string vPath = "Resource/shader/shader_v_1.glsl";
	std::string fPath = "Resource/shader/shader_f_1.glsl";

	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->loadVertexAndFragmentShader(vPath, fPath);
	pProgram->link();

	GLDebug::showError();
	auto pUniformBlock = pProgram->getUniformBlock("Uniforms");
	if (pUniformBlock)
	{
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
		GLDebug::showError();
	}
}

void ShaderScene::testSubroutineUniform()
{
	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	std::string vlPath = "Resource/shader/lighting.glsl";
	if (!pProgram->loadFromFile(ShaderType::VERTEX_SHADER, vlPath))
	{
		return;
	}
	pProgram->link();
	GLDebug::showError();
	auto pSubroutineUniform = pProgram->getSubroutineUniform(ShaderType::VERTEX_SHADER, "materialShader");
	GLDebug::showError();
	if (pSubroutineUniform)
	{
		uint32_t index = pSubroutineUniform->getSubroutineIndex("ambient");
		GLDebug::showError();
		pSubroutineUniform->setSubroutineIndex(index);
		GLDebug::showError();
	}
}

