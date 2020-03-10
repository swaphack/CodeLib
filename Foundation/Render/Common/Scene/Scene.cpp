#include "Scene.h"
#include "ext-config.h"
using namespace render;


Scene::Scene()
:_view(nullptr)
{

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

View* Scene::getView()
{
	return _view;
}

void Scene::setView(View* view)
{
	_view = view;
}
