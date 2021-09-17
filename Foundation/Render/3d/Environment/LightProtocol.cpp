#include "LightProtocol.h"
#include "mathlib.h"
#include "Graphic/import.h"
#include "Environment.h"
#include "Common/Scene/Camera.h"
#include "Light.h"
#include "Common/Node/Node.h"
#include "Common/Shader/import.h"
#include "PointLight.h"
#include "DirectionLight.h"
#include "SpotLight.h"

render::LightProtocol::LightProtocol()
{

}

render::LightProtocol::~LightProtocol()
{

}

void render::LightProtocol::setSupportLight(bool supported)
{
	_bSupportLight = supported;
}

bool render::LightProtocol::isSupportedLight()
{
	return _bSupportLight;
}

void render::LightProtocol::setSupportMultiLight(bool supported)
{
	_bSupportMultiLight = supported;
}

bool render::LightProtocol::isSupportedMultiLight()
{
	return _bSupportMultiLight;
}

void render::LightProtocol::setCastShadow(bool show)
{
	_bCastShadow = show;
}

bool render::LightProtocol::isCastShadow()
{
	return _bCastShadow;
}

void render::LightProtocol::setRecieveShadow(bool recieve)
{
	_bRecieveShadow = recieve;
}

bool render::LightProtocol::isRecieveShadow()
{
	return _bRecieveShadow;
}
