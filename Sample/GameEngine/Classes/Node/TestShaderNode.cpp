#include "TestShaderNode.h"
#include "mathlib.h"
#include "../Env/Utility.h"
#include "ui.h"
using namespace render;
using namespace math;
using namespace ui;

TestShaderNode::TestShaderNode()
{

}

TestShaderNode::~TestShaderNode()
{

}

void TestShaderNode::initNodes()
{
	this->addLight();
	/*
	
	//this->testImageShader();
	//this->testClipShader();
	this->testFbxModelShader();
	this->testObjModelShader();
	this->test3dsModelShader();

	//this->testCubeModelShader();
	//this->testMultiMeshCubeModelShader();
	this->testSphereModelShader();
	*/
	this->testTessellation();
}	

void TestShaderNode::testShaderUniformBlock()
{
	std::string vPath = "Shader/shader_v_1.glsl";
	std::string fPath = "Shader/shader_f_1.glsl";

	VertexFragmentShaderProgram* pProgram = CREATE_OBJECT(VertexFragmentShaderProgram);
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
	if (!pProgram->loadShaderFromFile(ShaderType::VERTEX_SHADER, vlPath))
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
	auto frameSize = render::Tool::getViewSize();

	std::string filepath = "Resource/Image/world.jpg";

	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath(filepath);
	pImage->setAnchorPoint(Vector2(0.5f, 0.5f));
	pImage->setVolume(800, 600);
	pImage->setPosition(Vector2(512, 384));
	this->addChild(pImage);

	//Utility::updateNodeShader(pImage);

	Utility::loadShaderVF(pImage, "Shader/vertex/test.vs", "Shader/fragment/test.fs");
}

void TestShaderNode::testCubeModelShader()
{
	std::string filepath = "Resource/Image/NeHe.png";

	Cube* pModel = CREATE_NODE(Cube);
	pModel->setTexture(filepath);
	pModel->setPosition(100, 100, 0);
	pModel->setVolume(200, 200, 200);
	pModel->setAnchorPoint(0.5f, 0.5f, 0.5f);
	this->addChild(pModel);

	Utility::loadDefaultShader(pModel);
	Utility::runRotateAction(pModel);
}

void TestShaderNode::testMultiMeshCubeModelShader()
{
	std::string filepath = "Resource/Image/NeHe.png";
	std::string filepath1 = "Resource/Image/1.jpg";

	MultiFaceCube* pModel = CREATE_NODE(MultiFaceCube);
	pModel->setAllFacesTexture(filepath);
	pModel->setFaceTexture(CubeFace::FRONT, filepath1);
	pModel->setFaceTexture(CubeFace::LEFT, filepath1);
	pModel->setFaceTexture(CubeFace::TOP, filepath1);

	pModel->setPosition(400, 400, 0);
	pModel->setVolume(200, 200, 200);
	pModel->setAnchorPoint(0.0f, 0.5f, 0.5f);
	this->addChild(pModel);

	Utility::loadDefaultShader(pModel);
	Utility::runRotateAction(pModel);
}

void TestShaderNode::testSphereModelShader()
{
	auto pTexture = G_TEXTURE_CACHE->createTexture2D("Resource/Image/world_texture.jpg");
	render::Sphere* pModel = CREATE_NODE(render::Sphere);
	pModel->setTexture(pTexture);
	pModel->setRadius(200);
	pModel->setVolume(400, 400, 400);
	pModel->setAnchorPoint(0.5, 0.5f, 0.5f);
	pModel->setPosition(512, 384, 0);
	this->addChild(pModel);

	Utility::loadShaderVF(pModel, "Shader/material/material_texture.vs", "Shader/material/material_texture.fs");
	Utility::runRotateAction(pModel);
}

void TestShaderNode::test3dsModelShader()
{
	std::string filename = "Resource/Model/3DS/Bld_38.3ds";

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

	Utility::loadShaderVF(pModel, "Shader/material/material_texture.vs", "Shader/material/material_texture.fs");
	Utility::runRotateAction(pModel);
}

void TestShaderNode::testObjModelShader()
{
	std::string filename = "Resource/Model/Obj/Skull_v3_L2/12140_Skull_v3_L2.obj";

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

	Utility::loadShaderVF(pModel, "Shader/material/material_texture.vs", "Shader/material/material_texture.fs");
	Utility::runRotateAction(pModel);
}

void TestShaderNode::testFbxModelShader()
{
	std::string filename = "Resource/Model/fbx/LANCER_EVOLUTION/LANCEREVOX.FBX";

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

	Utility::loadShaderVF(pModel, "Shader/material/material_texture.vs", "Shader/material/material_texture.fs");
	Utility::runRotateAction(pModel);
}

void TestShaderNode::addLight()
{
	render::Sphere* light = CREATE_NODE(render::Sphere);
	light->setPosition(200, 500);
	light->setRadius(50);
	Utility::loadShaderVF(light, "Shader/env/light.vs", "Shader/env/light.fs");
	this->addChild(light);

	Light* pSpotLight = CREATE_NODE(Light);
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
	pModel->setTexture(pTexture);
	pModel->setPosition(400, 400, 0);
	pModel->setVolume(200, 200, 200);
	pModel->setAnchorPoint(0.0f, 0.5f, 0.5f);
	this->addChild(pModel);

	std::string textureClipVertexPath = "Shader/clip.vs";

	VertexFragmentShaderProgram* pProgram = CREATE_OBJECT(VertexFragmentShaderProgram);
	pProgram->loadVertexAndFragmentShader(textureClipVertexPath, "Shader/texture/texture.fs");
	pProgram->link();


	pModel->getMaterial()->setShaderProgram(pProgram);
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

void TestShaderNode::testTessellation()
{
	auto frameSize = render::Tool::getViewSize();

	std::string filepath = "Resource/Image/world.jpg";

	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setName("Tess");
	pImage->setImagePath(filepath);
	pImage->setAnchorPoint(Vector2(0.5f, 0.5f));
	pImage->setVolume(800, 600);
	pImage->setPosition(Vector2(512, 384));
	this->addChild(pImage);
	/*
	Utility::loadShaderVF(pImage->getRenderNode(),
		"Shader/texture/texture.vs",
		"Shader/texture/texture.fs");
	*/
	float innerValue[2] = { 8, 0};
	float outerValue[4] = { 10,10,10,0 };
	pImage->getRenderNode()->setEnableTessilation(true);
	pImage->getRenderNode()->setTessVerticeCount(3);
	pImage->getRenderNode()->setTessInnerLevel(innerValue);
	pImage->getRenderNode()->setTessOuterLevel(outerValue);

	pImage->getRenderNode()->getMesh()->setDrawMode(DrawMode::LINES);

	if (true)
	{
		Utility::loadShaderVTGF(pImage->getRenderNode(),
			"Shader/tess/line_strip.vs",
			"Shader/tess/line_strip.tcs",
			"Shader/tess/line_strip.tes",
			"Shader/tess/line_strip.gs",
			"Shader/tess/line_strip.fs");
	}
	else
	{
		Utility::loadShaderVTGF(pImage->getRenderNode(),
			"Shader/tess/triangles.vs",
			"Shader/tess/triangles.tcs",
			"Shader/tess/triangles.tes",
			"Shader/tess/triangles.gs",
			"Shader/tess/triangles.fs");
	}	
}


