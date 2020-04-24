#include "GLLight.h"
#include "macros.h"
using namespace render;

void GLLight::getLight(LightName name, LightParameter mode, float* value)
{
	glGetLightfv((GLenum)name, (GLenum)mode, value);
}

void GLLight::setLightModel(LightModelParameter type, const float* value)
{
	glLightModelfv((GLenum)type, value);
}

void GLLight::setLightModel(LightModel type, float value)
{
	glLightModelf((GLenum)type, value);
}

void GLLight::setLightModelAmbient(const float* value)
{
	setLightModel(LightModelParameter::LIGHT_MODEL_AMBIENT, value);
}

void GLLight::setLightModelLocalViewer(const float* value)
{
	setLightModel(LightModelParameter::LIGHT_MODEL_LOCAL_VIEWER, value);
}

void GLLight::setLightModelTwoSide(const float* value)
{
	setLightModel(LightModelParameter::LIGHT_MODEL_TWO_SIDE, value);
}

void GLLight::setLight(LightName name, LightParameter type, const float* value)
{
	glLightfv((GLenum)name, (GLenum)type, value);
}

void GLLight::setLightAmbient(LightName name, const float* value)
{
	setLight(name, LightParameter::AMBIENT, value);
}

void GLLight::setLightAmbient(LightName  name, const math::Vector4& value)
{
	setLightAmbient(name, value.getValue());
}

void GLLight::setLightDiffuse(LightName  name, const math::Vector4& value)
{
	setLightDiffuse(name, value.getValue());
}

void GLLight::setLightSpecular(LightName  name, const math::Vector4& value)
{
	setLightSpecular(name, value.getValue());
}

void GLLight::setLightPosition(LightName  name, const math::Vector4& value)
{
	setLightPosition(name, value.getValue());
}

void GLLight::setLightSpotDirection(LightName  name, const math::Vector3& value)
{
	setLightSpotDirection(name, value.getValue());
}

void GLLight::setLightDiffuse(LightName  name, const float* value)
{
	setLight(name, LightParameter::DIFFUSE, value);
}

void GLLight::setLightSpecular(LightName  name, const float* value)
{
	setLight(name, LightParameter::SPECULAR, value);
}

void GLLight::setLightPosition(LightName  name, const float* value)
{
	setLight(name, LightParameter::POSITION, value);
}

void GLLight::setLightSpotDirection(LightName  name, const float* value)
{
	setLight(name, LightParameter::SPOT_DIRECTION, value);
}

void GLLight::setLightSpotExponent(LightName  name, float value)
{
	setLight(name, LightParameter::SPOT_EXPONENT, &value);
}

void GLLight::setLightSpotCutOff(LightName  name, float value)
{
	setLight(name, LightParameter::SPOT_CUTOFF, &value);
}

void GLLight::setLightConstantAttenuation(LightName  name, float value)
{
	setLight(name, LightParameter::CONSTANT_ATTENUATION, &value);
}

void GLLight::setLightLinearAttenuation(LightName  name, float value)
{
	setLight(name, LightParameter::LINEAR_ATTENUATION, &value);
}

void GLLight::setLightQuadraticAttenuation(LightName  name, float value)
{
	setLight(name, LightParameter::QUADRATIC_ATTENUATION, &value);
}
