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
	int index = _lights.size();
	light->setLightIndex(index);

	auto it = _lights.find(index);

	ASSERT(it == _lights.end());

	_lights[index] = light;
}

void render::Environment::removeLight(Light* light)
{
	if (light == nullptr)
	{
		return;
	}
	int index = light->getLightIndex();
	auto it = _lights.find(index);
	if (it != _lights.end())
	{
		_lights.erase(it);
	}
}

render::Light* render::Environment::getLight(int index) const
{
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

void render::Environment::setGamma(float value)
{
	_gamma = value;
}

float render::Environment::getGamma() const
{
	return _gamma;
}

