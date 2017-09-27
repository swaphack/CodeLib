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
	// Ä£ÐÍ¾ØÕó
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

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

Camera* Scene::getCamera()
{
	if (_view == nullptr)
	{
		return nullptr;
	}

	return _view->getCamera();
}
