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
	//this->testImageShader();
	//this->test3dsModelShader();
	this->testModelShader();
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

	std::string vPath = "Resource/shader/texture2d.vsh";
	std::string fPath = "Resource/shader/texture2d.fsh";

	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->loadVertexAndFragmentShader(vPath, fPath);
	pProgram->link();

	/*
	pModel->getMaterial()->setShaderProgram(pProgram);
	pModel->getMaterial()->addAttrib(VertexAttribType::POSITION, "vertexPosition");
	pModel->getMaterial()->addAttrib(VertexAttribType::COLOR, "vertexColor");
	pModel->getMaterial()->addAttrib(VertexAttribType::UV, "vertexUV");
	*/

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(180, 180, 180);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pImage->getActionProxy()->runAction(pRepeateAction);
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
}

void TestShaderNode::testModelShader()
{
	auto pTexture = G_TEXTURE_CACHE->createTexture2D("Resource/Image/NeHe.png");
	auto pTexture1 = G_TEXTURE_CACHE->createTexture2D("Resource/Image/1.jpg");
	std::string textureName = "face";
	std::string textureName1 = "face1";

	CubeModel* pModel = CREATE_NODE(CubeModel);
	pModel->addTexture(textureName, pTexture);
	pModel->addTexture(textureName1, pTexture1);

	pModel->setAllFacesTexture(textureName);
	pModel->setFaceTexture(EMF_FRONT, textureName1);
	pModel->setFaceTexture(EMF_LEFT, textureName1);
	pModel->setFaceTexture(EMF_TOP, textureName1);

	pModel->setAnchorPoint(math::Vector3(0.5f, 0.5f, 0.5f));
	pModel->setPosition(400, 400, 0);
	pModel->setVolume(200, 200, 200);
	pModel->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pModel);

	std::string vPath = "Resource/shader/texture3d.vsh";
	std::string fPath = "Resource/shader/texture3d.fsh";

	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->loadVertexAndFragmentShader(vPath, fPath);
	pProgram->link();

	pModel->getMaterial()->setShaderProgram(pProgram);

	pModel->getMaterial()->addUniform(VertexUniformType::PROJECT_MATRIX, "projMat");
	pModel->getMaterial()->addUniform(VertexUniformType::VIEW_MATRIX, "viewMat");
	pModel->getMaterial()->addUniform(VertexUniformType::MODEL_VIEW, "modelMat");

	pModel->getMaterial()->addAttrib(VertexAttribType::POSITION, "vertexPosition");
	pModel->getMaterial()->addAttrib(VertexAttribType::COLOR, "vertexColor");
	pModel->getMaterial()->addAttrib(VertexAttribType::UV, "vertexUV");

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(0, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pModel->getActionProxy()->runAction(pRepeateAction);
}

void TestShaderNode::test3dsModelShader()
{
	Model3DS* pModel = CREATE_NODE(Model3DS);
	pModel->load("Resource/3DS/Bld_38.3ds");
	pModel->setScale(20);
	pModel->setPosition(500, 500, 0);
	pModel->setVolume(400, 400, 400);
	this->addChild(pModel);

	std::string vPath = "Resource/shader/texture3d.vsh";
	std::string fPath = "Resource/shader/texture3d.fsh";

	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->loadVertexAndFragmentShader(vPath, fPath);
	pProgram->link();

	pModel->getMaterial()->setShaderProgram(pProgram);

	pModel->getMaterial()->addUniform(VertexUniformType::PROJECT_MATRIX, "projMat");
	pModel->getMaterial()->addUniform(VertexUniformType::VIEW_MATRIX, "viewMat");
	pModel->getMaterial()->addUniform(VertexUniformType::MODEL_VIEW, "modelMat");

	pModel->getMaterial()->addAttrib(VertexAttribType::POSITION, "vertexPosition");
	pModel->getMaterial()->addAttrib(VertexAttribType::COLOR, "vertexColor");
	pModel->getMaterial()->addAttrib(VertexAttribType::UV, "vertexUV");

	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(180, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	pModel->getActionProxy()->runAction(pRepeateAction);
}

