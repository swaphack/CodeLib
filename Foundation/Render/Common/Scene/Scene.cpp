#include "Scene.h"
#include "Common/View/import.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"

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

	
	if (Camera::getMainCamera()->getDimensions() == CameraDimensions::THREE)
	{
		auto size = Tool::getGLViewSize();
		//Camera::getMainCamera()->lookAt(math::Vector3(0, 0));
		Camera::getMainCamera()->lookAt(math::Vector3(size.getWidth() * 0.5f, size.getHeight() * 0.5f));
	}

	this->drawNode();
}
