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

	//this->addChild(CREATE_NODE(TestModelNode));
	
	//this->addChild(CREATE_NODE(TestLayoutNode));
	//this->addChild(CREATE_NODE(TestMediaNode));
	//this->addChild(CREATE_NODE(TestImageNode));
	this->addChild(CREATE_NODE(TestShaderNode));

	return true;
}