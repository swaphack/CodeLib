#include "TestMainScene.h"
#include "../Node/import.h"
#include "../Env/import.h"

TestMainScene::TestMainScene()
{

}

TestMainScene::~TestMainScene()
{

}

bool TestMainScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto boxDraw = G_BOXSPACE->getBoxDraw();
	if (boxDraw)
	{
		Utility::loadPrimitiveShader(boxDraw->getRenderNode2d());
		Utility::loadPrimitiveShader(boxDraw->getRenderNode3d());
	}	

	this->initNodes();
	this->initEnv();

	return true;
}

void TestMainScene::initNodes()
{

	//this->addChild(CREATE_NODE(TestModelNode));

	//this->addChild(CREATE_NODE(TestShaderNode));
	//this->addChild(CREATE_NODE(TestTextNode));
	//this->addChild(CREATE_NODE(TestLayoutNode));
	//this->addChild(CREATE_NODE(TestMediaNode));
	//this->addChild(CREATE_NODE(TestFragmentNode));
	//this->addChild(CREATE_NODE(TestDrawNode));
	//this->addChild(CREATE_NODE(TestUINode));
	//
	this->addChild(CREATE_NODE(TestParticleNode));
	//
	//this->addChild(CREATE_NODE(TestTextureNode));
	//
	//this->addChild(CREATE_NODE(TestPostProcessing));
	//
	//this->addChild(CREATE_NODE(TestComputeShader));
	//
	//this->addChild(CREATE_NODE(TestLightingNode));
	//
	//this->addChild(CREATE_NODE(TestXFBNode));
	//
	//this->addChild(CREATE_NODE(TestImageNode));
	//
	//this->addChild(CREATE_NODE(TestMeshNode));
	//
	//this->addChild(CREATE_NODE(TestMathNode));

	//this->addChild(CREATE_NODE(TestAlgNode));

	this->addChild(CREATE_NODE(TestTool));
}

void TestMainScene::initEnv()
{
	this->addChild(CREATE_NODE(SystemEnv));
	//this->addChild(CREATE_NODE(TerrianNode));


	this->addChild(CREATE_NODE(TestEnvironmentNode));
}
