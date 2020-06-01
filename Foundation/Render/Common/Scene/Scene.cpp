#include "Scene.h"
#include "Common/View/import.h"
#include "Graphic/import.h"

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

	return true;
}

void Scene::visit()
{
	this->updateNode();

	// Ä£ÐÍ¾ØÕó
	GLMatrix::applyModelView();

	//Camera::getMainCamera()->lookAt(math::Vector3());

	this->drawNode();
}
