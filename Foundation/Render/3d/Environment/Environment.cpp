#include "Environment.h"
#include "Light.h"

render::Environment::Environment()
{

}

render::Environment::~Environment()
{

}

void render::Environment::addLight(Light* light)
{
	if (light == nullptr)
	{
		return;
	}
	int index = (int)light->getLightName();
	_lights[index] = light;
}

void render::Environment::removeLight(Light* light)
{
	if (light == nullptr)
	{
		return;
	}
	int index = (int)light->getLightName();
	auto it = _lights.find(index);
	if (it != _lights.end())
	{
		_lights.erase(it);
	}
}

render::Light* render::Environment::getLight(LightName name) const
{
	int index = (int)name;
	auto it = _lights.find(index);
	if (it != _lights.end())
	{
		return it->second;
	}

	return nullptr;
}

const std::map<int, render::Light*>& render::Environment::getAllLights() const
{
	return _lights;
}

bool render::Environment::hasLight() const
{
	return _lights.size() > 0;
}

