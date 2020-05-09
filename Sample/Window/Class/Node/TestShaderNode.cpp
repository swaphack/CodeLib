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
	//this->testModelShader();
	this->test3dsModelShader();
	this->testFbxModelShader();
	this->testObjModelShader();
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
	pImage->setAnchorPoint(Vector2(0.5f, 0.5f));
	pImage->setVolume(500, 500);
	pImage->setPosition(Vector2(500, 500));
	this->addChild(pImage);

	std::string vPath = "Resource/shader/texture2d.vsh";
	std::string fPath = "Resource/shader/texture2d.fsh";

	loadShader(pImage->getMaterial(), vPath, fPath);
	initShaderAttrib(pImage->getMaterial());
	runRotateAction(pImage);
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

	loadShader(pModel->getMaterial(), vPath, fPath);
	initShaderAttrib(pModel->getMaterial());
	runRotateAction(pModel);
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

	loadShader(pModel->getMaterial(), vPath, fPath);
	initShaderAttrib(pModel->getMaterial());
	runRotateAction(pModel);
}

void TestShaderNode::testObjModelShader()
{
	std::string filename = "Resource/Obj/Skull_v3_L2/12140_Skull_v3_L2.obj";

	ModelObj* pModel = CREATE_NODE(ModelObj);
	pModel->load(filename);
	pModel->setScale(5);
	pModel->setPosition(512, 384, 0);
	pModel->setVolume(400, 400, 400);
	this->addChild(pModel);

	std::string vPath = "Resource/shader/texture3d.vsh";
	std::string fPath = "Resource/shader/texture3d.fsh";

	loadShader(pModel->getMaterial(), vPath, fPath);
	initShaderAttrib(pModel->getMaterial());
	runRotateAction(pModel);
}

void TestShaderNode::testFbxModelShader()
{
	std::string filename = "Resource/fbx/LANCER_EVOLUTION/LANCEREVOX.FBX";

	ModelFbx* pModel = CREATE_NODE(ModelFbx);
	pModel->load(filename);
	pModel->setScale(200);
	pModel->setRotationX(0);
	this->addChild(pModel);

	std::string vPath = "Resource/shader/texture3d.vsh";
	std::string fPath = "Resource/shader/texture3d.fsh";

	loadShader(pModel->getMaterial(), vPath, fPath);
	initShaderAttrib(pModel->getMaterial());
	runRotateAction(pModel);
}

void TestShaderNode::loadShader(render::Material* mat, const std::string& vpath, const std::string& fpath)
{
	if (mat == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->loadVertexAndFragmentShader(vpath, fpath);
	pProgram->link();

	mat->setShaderProgram(pProgram);
}

void TestShaderNode::initShaderAttrib(render::Material* mat)
{
	if (mat == nullptr)
	{
		return;
	}

	mat->addUniform(VertexUniformType::PROJECT_MATRIX, "projMat");
	mat->addUniform(VertexUniformType::VIEW_MATRIX, "viewMat");
	mat->addUniform(VertexUniformType::MODEL_VIEW, "modelMat");
	
	mat->addUniform(VertexUniformType::AMBIENT_TEXTURE, "texSampler0");
	mat->addUniform(VertexUniformType::DIFFUSE_TEXTURE, "texSampler1");
	
	mat->addAttrib(VertexAttribType::POSITION, "vertexPosition");
	mat->addAttrib(VertexAttribType::COLOR, "vertexColor");
	mat->addAttrib(VertexAttribType::UV, "vertexUV");
}

void TestShaderNode::runRotateAction(render::Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(180, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	node->getActionProxy()->runAction(pRepeateAction);
}

