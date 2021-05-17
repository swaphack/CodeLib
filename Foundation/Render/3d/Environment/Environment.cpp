#include "Environment.h"
#include "Light.h"
#include "Common/Shader/ShaderProgram.h"

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

void render::Environment::addCastShadowNode(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	_castShadowNodes.insert(node);
}

void render::Environment::removeCastShadowNode(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	_castShadowNodes.erase(node);
}

void render::Environment::addRecieveShadowNode(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	_recieveShadowNodes.insert(node);

}

void render::Environment::removeRecieveShadowNode(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	_recieveShadowNodes.insert(node);
}

void render::Environment::setCastShaderProgram(ShaderProgram* program)
{
	SAFE_RELEASE(_shadowShader.castShaderProgram);
	SAFE_RETAIN(program);
	_shadowShader.castShaderProgram = program;
}

void render::Environment::setRenderShaderProgram(ShaderProgram* program)
{
	SAFE_RELEASE(_renderShaderProgram);
	SAFE_RETAIN(program);
	_shadowShader.renderShaderProgram = program;
}

void render::Environment::setReceiveLightShaderProgram(ShaderProgram* program)
{
	SAFE_RELEASE(_shadowShader.receiveLightShaderProgram);
	SAFE_RETAIN(program);
	_shadowShader.receiveLightShaderProgram = program;
}

