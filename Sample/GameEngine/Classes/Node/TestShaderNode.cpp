#include "TestShaderNode.h"
#include "mathlib.h"
#include "ShaderUtility.h"
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
	//this->addLight();
	//this->testImageShader();
	this->testModelShader();
	//this->test3dsModelShader();
	//this->testFbxModelShader();
	//this->testObjModelShader();
}

void TestShaderNode::testShaderUniformBlock()
{
	std::string vPath = "Shader/shader_v_1.glsl";
	std::string fPath = "Shader/shader_f_1.glsl";

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
	std::string vlPath = "Shader/lighting.glsl";
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

	ShaderUtility::updateNodeShader(pImage, false);
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
	pModel->setFaceTexture(ModelFace::FRONT, textureName1);
	pModel->setFaceTexture(ModelFace::LEFT, textureName1);
	pModel->setFaceTexture(ModelFace::TOP, textureName1);

	pModel->setPosition(400, 400, 0);
	pModel->setVolume(200, 200, 200);
	pModel->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pModel);

	ShaderUtility::updateNodeShader(pModel);
}

void TestShaderNode::test3dsModelShader()
{
	Model3DS* pModel = CREATE_NODE(Model3DS);
	pModel->load("Resource/3DS/Bld_38.3ds");
	pModel->setScale(20);
	pModel->setPosition(500, 500, 0);
	pModel->setVolume(400, 400, 400);
	this->addChild(pModel);

	ShaderUtility::updateNodeShader(pModel);
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

	ShaderUtility::updateNodeShader(pModel);
}

void TestShaderNode::testFbxModelShader()
{
	std::string filename = "Resource/fbx/LANCER_EVOLUTION/LANCEREVOX.FBX";

	ModelFbx* pModel = CREATE_NODE(ModelFbx);
	pModel->load(filename);
	pModel->setScale(200);
	pModel->setRotationX(0);
	this->addChild(pModel);

	ShaderUtility::updateNodeShader(pModel);
}

void TestShaderNode::addLight()
{
	Light0* pSpotLight = CREATE_NODE(Light0);
	pSpotLight->setPosition(0, 0, 50);
	pSpotLight->setAmbient(255, 255, 255, 255);
	pSpotLight->setDiffuse(255, 255, 255, 255);
	pSpotLight->setSpecular(255, 255, 255, 255);

	this->addChild(pSpotLight);
}



