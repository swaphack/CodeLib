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

	this->addChild(CREATE_NODE(TestTextNode));

	return true;
}