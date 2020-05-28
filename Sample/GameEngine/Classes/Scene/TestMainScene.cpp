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

	
	//this->addChild(CREATE_NODE(TestShaderNode));
	
	//this->addChild(CREATE_NODE(TestLayoutNode));
	//this->addChild(CREATE_NODE(TestMediaNode));
	//this->addChild(CREATE_NODE(TestFragmentNode));
	//this->addChild(CREATE_NODE(TestDrawNode));
	//this->addChild(CREATE_NODE(TestUINode));

	this->addChild(CREATE_NODE(TestParticleNode));

	//this->addChild(CREATE_NODE(TestTextureNode));

	//this->addChild(CREATE_NODE(TestEnvironmentNode));

	return true;
}
