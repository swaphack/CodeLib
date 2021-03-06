#include "MultiSampling.h"
#include "Graphic/import.h"


bool render::MultiSampling::isSupport()
{
	int ret = 0;
	GLState::getInteger(GetTarget::SAMPLE_BUFFERS, &ret);
	return ret != 0;
}

void render::MultiSampling::enable()
{
	GLState::enable(EnableMode::MULTISAMPLE);
}

void render::MultiSampling::disable()
{
	GLState::disable(EnableMode::MULTISAMPLE);
}

void render::MultiSampling::enableShader()
{
	GLState::enable(EnableMode::SAMPLE_SHADING);
}

void render::MultiSampling::setMinSampleShader(float value)
{
	GLShader::setMinSampleShading(value);
}

void render::MultiSampling::disableShader()
{
	GLState::disable(EnableMode::SAMPLE_SHADING);
}

int render::MultiSampling::getSamples()
{
	int value = 0;
	GLState::getInteger(GetTarget::SAMPLES, &value);
	return value;
}

void render::MultiSampling::getMultiSample(uint32_t index, float* value)
{
	GLUtility::getMultiSample(index, value);
}
