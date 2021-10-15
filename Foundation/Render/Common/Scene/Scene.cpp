#include "Scene.h"
#include "Common/View/import.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"
#include "Box/BoxDraw.h"
#include "Camera2D.h"
#include "Camera3D.h"
#include "Cameras.h"
#include "DebugDraw.h"
#include "Common/DrawNode/DrawCore.h"

using namespace render;

Scene::Scene() 
{
	this->setRelativeWithParent(false);
}

Scene::~Scene()
{

}

bool Scene::init()
{
	if (!Node::init())
	{
		return false;
	}
	Camera3D* designCamera = CREATE_NODE(Camera3D);
	this->addChild(designCamera, INT_MIN);
	G_CAMERAS->setDesignCamera(designCamera);

	Camera3D* camera3D = CREATE_NODE(Camera3D);
	this->addChild(camera3D, INT_MIN);
	G_CAMERAS->setCamera3D(camera3D);

	Camera2D* camera2D = CREATE_NODE(Camera2D);
	this->addChild(camera2D, INT_MIN);
	G_CAMERAS->setCamera2D(camera2D);

	BoxDraw* boxDraw = CREATE_NODE(BoxDraw);
	this->addChild(boxDraw, INT_MAX);

	return true;
}

void Scene::visit()
{
	// 合批处理

	this->updateNode();

	G_DRAWCORE->batch();

	this->drawNode();

	G_DRAWCORE->unbatch();
}

void render::Scene::addChild(Node* node)
{
	Scene::addChild(node, 0);
}

void render::Scene::addChild(Node* node, int zOrder)
{
	Node::addChild(node, zOrder);
	node->setChildrenScene(this);
}
