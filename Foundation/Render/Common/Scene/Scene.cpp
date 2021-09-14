#include "Scene.h"
#include "Common/View/import.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"
#include "Box/BoxDraw.h"
#include "Common/View/Cameras.h"

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

	Camera3D* camera3D = CREATE_NODE(Camera3D);
	this->addChild(camera3D, INT_MAX);
	G_CAMERAS->setCamera3D(camera3D);

	Camera2D* camera2D = CREATE_NODE(Camera2D);
	this->addChild(camera2D, INT_MAX);
	G_CAMERAS->setCamera2D(camera2D);

	BoxDraw* box = CREATE_NODE(BoxDraw);
	this->addChild(box, INT_MAX);


	return true;
}

void Scene::visit()
{
	// Ä£ÐÍ¾ØÕó
	GLMatrix::applyModelView();

	this->updateNode();

	this->drawNode();
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
