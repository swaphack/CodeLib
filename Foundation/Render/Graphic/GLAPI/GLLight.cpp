#include "GLLight.h"
#include "macros.h"
using namespace render;

void GLLight::setLightModel(int type, const float* value)
{
	glLightModelfv(type, value);
}

void GLLight::setLightModelAmbient(const float* value)
{
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, value);
}

void GLLight::setLightModelLocalViewer(const float* value)
{
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, value);
}

void GLLight::setLightModelTwoSide(const float* value)
{
	glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE, value);
}

void GLLight::setLight(LightName  name, int type, const float* value)
{
	glLightfv((GLenum)name, type, value);
}

void GLLight::setLightAmbient(LightName name, const float* value)
{
	setLight(name, GL_AMBIENT, value);
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
	setLight(name, GL_DIFFUSE, value);
}

void GLLight::setLightSpecular(LightName  name, const float* value)
{
	setLight(name, GL_SPECULAR, value);
}

void GLLight::setLightPosition(LightName  name, const float* value)
{
	setLight(name, GL_POSITION, value);
}

void GLLight::setLightSpotDirection(LightName  name, const float* value)
{
	setLight(name, GL_SPOT_DIRECTION, value);
}

void GLLight::setLightSpotExponent(LightName  name, float value)
{
	setLight(name, GL_SPOT_EXPONENT, &value);
}

void GLLight::setLightSpotCutOff(LightName  name, float value)
{
	setLight(name, GL_SPOT_CUTOFF, &value);
}

void GLLight::setLightConstantAttenuation(LightName  name, float value)
{
	setLight(name, GL_CONSTANT_ATTENUATION, &value);
}

void GLLight::setLightLinearAttenuation(LightName  name, float value)
{
	setLight(name, GL_LINEAR_ATTENUATION, &value);
}

void GLLight::setLightQuadraticAttenuation(LightName  name, float value)
{
	setLight(name, GL_QUADRATIC_ATTENUATION, &value);
}
