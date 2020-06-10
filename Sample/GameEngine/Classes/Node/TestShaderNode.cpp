#include "TestShaderNode.h"
#include "mathlib.h"
#include "Utility.h"
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
	this->addLight();
	//this->testImageShader();
	//this->testClipShader();
	//this->testFbxModelShader();
	//this->testObjModelShader();
	//this->test3dsModelShader();

	//this->testCubeModelShader();
	//this->testMultiMeshCubeModelShader();
	this->testSphereModelShader();
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

			NoNamedBuffer* pObject = CREATE_OBJECT(NoNamedBuffer);
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
	pImage->setVolume(800, 600);
	pImage->setPosition(Vector2(512, 384));
	this->addChild(pImage);

	Utility::updateNodeShader(pImage);
}

void TestShaderNode::testCubeModelShader()
{
	std::string filepath = "Resource/Image/NeHe.png";

	Cube* pModel = CREATE_NODE(Cube);
	pModel->setFaceImage(filepath);
	pModel->setPosition(500, 500, 0);
	pModel->setVolume(200, 200, 200);
	pModel->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pModel);

	Utility::updateNodeShader(pModel);
	Utility::runRotateAction(pModel);
}

void TestShaderNode::testMultiMeshCubeModelShader()
{
	std::string filepath = "Resource/Image/NeHe.png";
	std::string filepath1 = "Resource/Image/1.jpg";

	MultiFaceCube* pModel = CREATE_NODE(MultiFaceCube);
	pModel->setAllFacesImage(filepath);
	pModel->setFaceImage(CubeFace::FRONT, filepath1);
	pModel->setFaceImage(CubeFace::LEFT, filepath1);
	pModel->setFaceImage(CubeFace::TOP, filepath1);

	pModel->setPosition(400, 400, 0);
	pModel->setVolume(200, 200, 200);
	pModel->setAnchorPoint(0.0f, 0.5f, 0.5f);
	this->addChild(pModel);

	Utility::updateNodeShader(pModel);
	Utility::runRotateAction(pModel);
}

void TestShaderNode::testSphereModelShader()
{
	auto pTexture = G_TEXTURE_CACHE->createTexture2D("Resource/Image/world_texture.jpg");
	render::Sphere* pModel = CREATE_NODE(render::Sphere);
	pModel->setAllMaterialsTexture(pTexture);
	pModel->setRadius(200);
	pModel->setVolume(400, 400, 400);
	pModel->setAnchorPoint(0.5, 0.5f, 0.5f);
	pModel->setPosition(752, 200, 0);
	this->addChild(pModel);

	Utility::loadShader(pModel->getMaterials(), "Shader/simple_texture.vs", "Shader/simple_texture.fs");
	Utility::runRotateAction(pModel);

	pModel->getTouchProxy()->addTouchFunc(render::TouchType::DOWN, [](Node* node, float x, float y, bool include) {
		auto sphere = node->as<render::Sphere>();
		if (sphere == nullptr)
		{
			return;
		}

		sphere->setBoxVisible(true);
	});

	pModel->getTouchProxy()->addTouchFunc(render::TouchType::UP, [](Node* node, float x, float y, bool include) {
		auto sphere = node->as<render::Sphere>();
		if (sphere == nullptr)
		{
			return;
		}

		sphere->setBoxVisible(false);
	});
}

void TestShaderNode::test3dsModelShader()
{
	std::string filename = "Resource/3DS/Bld_38.3ds";

	Model3DS* pModel = CREATE_NODE(Model3DS);
	if (!pModel->load(filename))
	{
		SAFE_DELETE(pModel);
		return;
	}
	pModel->setScale(20);
	pModel->setPosition(500, 500, 0);
	pModel->setVolume(400, 400, 400);
	this->addChild(pModel);

	Utility::loadShader(pModel->getMaterials(), "Shader/simple_texture.vs", "Shader/simple_texture.fs");
	Utility::runRotateAction(pModel);
}

void TestShaderNode::testObjModelShader()
{
	std::string filename = "Resource/Obj/Skull_v3_L2/12140_Skull_v3_L2.obj";

	ModelObj* pModel = CREATE_NODE(ModelObj);
	if (!pModel->load(filename))
	{
		SAFE_DELETE(pModel);
		return;
	}
	pModel->setScale(50);
	pModel->setPosition(512, 384, 0);
	pModel->setVolume(400, 400, 400);
	this->addChild(pModel);

	Utility::loadShader(pModel->getMaterials(), "Shader/simple_texture.vs", "Shader/simple_texture.fs");
	Utility::runRotateAction(pModel);
}

void TestShaderNode::testFbxModelShader()
{
	std::string filename = "Resource/fbx/LANCER_EVOLUTION/LANCEREVOX.FBX";

	ModelFbx* pModel = CREATE_NODE(ModelFbx);
	if (!pModel->load(filename))
	{
		SAFE_DELETE(pModel);
		return;
	}
	pModel->setScale(200);
	pModel->setPosition(512, 384, 0);
	pModel->setRotationX(0);
	this->addChild(pModel);

	Utility::loadShader(pModel->getMaterials(), "Shader/simple_texture.vs", "Shader/simple_texture.fs");
	Utility::runRotateAction(pModel);
}

void TestShaderNode::addLight()
{
	render::Sphere* light = CREATE_NODE(render::Sphere);
	light->setPosition(200, 500);
	light->setRadius(50);
	Utility::loadShader(light->getMaterials(), "Shader/light.vs", "Shader/light.fs");
	this->addChild(light);

	Light0* pSpotLight = CREATE_NODE(Light0);
	pSpotLight->setAmbient(255, 255, 255, 255);
	pSpotLight->setDiffuse(255, 255, 255, 255);
	pSpotLight->setSpecular(255, 255, 255, 255);
	light->addChild(pSpotLight);
}

void TestShaderNode::testClipShader()
{
	auto pTexture = G_TEXTURE_CACHE->createTexture2D("Resource/Image/NeHe.png");
	std::string textureName = "face";

	MultiFaceCube* pModel = CREATE_NODE(MultiFaceCube);
	pModel->addMaterialTexture(textureName, pTexture);

	pModel->setAllMaterialsTexture(textureName);
	pModel->setPosition(400, 400, 0);
	pModel->setVolume(200, 200, 200);
	pModel->setAnchorPoint(0.0f, 0.5f, 0.5f);
	this->addChild(pModel);

	std::string textureClipVertexPath = "Shader/clip.vs";

	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->loadVertexAndFragmentShader(textureClipVertexPath, Utility::texture3dFragmentPath);
	pProgram->link();


	pModel->getMaterial()->setShaderProgram(pProgram);
	Utility::initShaderAttrib(pModel->getMaterials());
	Utility::runRotateAction(pModel);


	pModel->getMaterial()->setProgramFunc([](ShaderProgram* program) {
		auto pUniform = program->getUniform("Plane");
		if (pUniform)
		{
			float param[4] = { 1, 0, 0, -400 };
			pUniform->setValue4(1, param);
		}
	});
}


