#include "TestMainScene.h"
#include "../Node/import.h"

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

	//this->addChild(CREATE_NODE(TestEnvironmentNode));
	//this->addChild(CREATE_NODE(TestModelNode));
	
	//this->addChild(CREATE_NODE(TestShaderNode));
	
	//this->addChild(CREATE_NODE(TestLayoutNode));
	//this->addChild(CREATE_NODE(TestMediaNode));
	//this->addChild(CREATE_NODE(TestFragmentNode));
	//this->addChild(CREATE_NODE(TestDrawNode));
	//this->addChild(CREATE_NODE(TestUINode));

	//this->addChild(CREATE_NODE(TestParticleNode));

	//this->addChild(CREATE_NODE(TestTextureNode));

	//this->addChild(CREATE_NODE(TestPostProcessing));

	//this->addChild(CREATE_NODE(TestComputeShader));

	//this->addChild(CREATE_NODE(TestLightingNode));

	//this->addChild(CREATE_NODE(TestXFBNode));

	//this->addChild(CREATE_NODE(TestImageNode));

	this->addChild(CREATE_NODE(TestMeshNode));

	this->addChild(CREATE_NODE(TestMathNode));

	return true;
}
