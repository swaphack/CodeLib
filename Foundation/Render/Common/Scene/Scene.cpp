#include "Scene.h"

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

View* render::Scene::getView()
{
	return _view;
}

void render::Scene::setView(View* view)
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
