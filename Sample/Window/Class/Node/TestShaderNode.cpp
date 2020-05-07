#include "TestShaderNode.h"
#include "mathlib.h"

using namespace render;
using namespace math;

TestShaderNode::TestShaderNode()
{

}

TestShaderNode::~TestShaderNode()
{

}

void TestShaderNode::testFunc()
{
	//this->testColorShader();
	this->testImageShader();
	//this->testModelShader();
}

void TestShaderNode::testShaderUniformBlock()
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

			NoNamedBufferObject* pObject = CREATE_OBJECT(NoNamedBufferObject);
			pObject->setBufferTarget(BufferTarget::UNIFORM_BUFFER);
			pObject->bindBuffer();
			pObject->setBufferData(blockData.getBlockData().getSize(), blockData.getBlockData().getValue(), BufferDataUsage::STATIC_DRAW);

			GLDebug::showError();
		}
		GLDebug::showError();
	}
}

void TestShaderNode::testSubroutineUniform()
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

void TestShaderNode::testImageShader()
{
	auto frameSize = Canvas::getInstance()->getView()->getFrameSize();

	std::string filepath = "Resource/Image/world.jpg";

	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath(filepath);
	pImage->setAnchorPoint(Vector2());
	pImage->setVolume(500, 500);
	pImage->setPosition(Vector2());
	this->addChild(pImage);

	std::string vPath = "Resource/shader/texture.vsh";
	std::string fPath = "Resource/shader/texture.fsh";

	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->loadVertexAndFragmentShader(vPath, fPath);
	pProgram->link();

	ShaderAttrib* pAttrib = pProgram->getAttrib("vertexPosition");
	if (pAttrib)
	{
		pProgram->addVertexAttrib(VertexAttribType::POSITION, pAttrib->getAttribID());
	}

	pAttrib = pProgram->getAttrib("vertexColor");
	if (pAttrib)
	{
		pProgram->addVertexAttrib(VertexAttribType::COLOR, pAttrib->getAttribID());
	}

	pAttrib = pProgram->getAttrib("vertexUV");
	if (pAttrib)
	{
		pProgram->addVertexAttrib(VertexAttribType::UV, pAttrib->getAttribID());
	}
	

	pImage->setProgram(pProgram);
}

void TestShaderNode::testColorShader()
{
	auto frameSize = Canvas::getInstance()->getView()->getFrameSize();

	std::string filepath = "Resource/Image/world.jpg";

	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath(filepath);
	pImage->setAnchorPoint(Vector2());
	pImage->setVolume(500, 500);
	pImage->setPosition(Vector2());
	this->addChild(pImage);

	std::string vPath = "Resource/shader/color.vsh";
	std::string fPath = "Resource/shader/color.fsh";

	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->loadVertexAndFragmentShader(vPath, fPath);
	pProgram->link();

	pImage->setProgram(pProgram);
}

void TestShaderNode::testModelShader()
{
	Model3DS* model = CREATE_NODE(Model3DS);
	model->load("Resource/3DS/Bld_38.3ds");
	model->setScale(100);
	model->setPosition(200, 200, -50);
	//model->setVolume(400, 400, 400);
	this->addChild(model);
	/*
	std::string vPath = "Resource/shader/color.vsh";
	std::string fPath = "Resource/shader/color.fsh";

	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->loadVertexAndFragmentShader(vPath, fPath);
	pProgram->link();

	model->setProgram(pProgram);
	*/
	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(180, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	model->getActionProxy()->runAction(pRepeateAction);
}
