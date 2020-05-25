#include "Sampler.h"
#include "Graphic/import.h"

render::Sampler::Sampler()
{
	this->initSampler();
}

render::Sampler::~Sampler()
{
	this->releaseSampler();
}

uint32_t render::Sampler::getSamplerID() const
{
	return _samplerID;
}

bool render::Sampler::isValid() const
{
	return GLSampler::isSampler(_samplerID);
}

void render::Sampler::bindTexture(uint32_t unit)
{
	GLSampler::bindSampler(unit, _samplerID);
}

void render::Sampler::unbindTexture(uint32_t unit)
{
	GLSampler::bindSampler(unit, 0);
}

void render::Sampler::setParameter(SamplerParameter name, int value)
{
	GLSampler::setSamplerParameter(_samplerID, name, value);
}

void render::Sampler::setParameter(SamplerParameter name, const float* value)
{
	GLSampler::setSamplerParameter(_samplerID, name, value);
}

void render::Sampler::apply(const TextureSetting& setting)
{
	this->setParameter(SamplerParameter::TEXTURE_MIN_FILTER, (int)setting.minFilter);
	this->setParameter(SamplerParameter::TEXTURE_MAG_FILTER, (int)setting.magFilter);
	this->setParameter(SamplerParameter::TEXTURE_WRAP_S, (int)setting.wrapS);
	this->setParameter(SamplerParameter::TEXTURE_WRAP_T, (int)setting.wrapT);
	GLDebug::showError();
}

void render::Sampler::setParameter(SamplerParameter name, const uint32_t* value)
{
	GLSampler::setSamplerParameter(_samplerID, name, value);
}

void render::Sampler::setParameter(SamplerParameter name, const int* value)
{
	GLSampler::setSamplerParameter(_samplerID, name, value);
}

void render::Sampler::setParameter(SamplerParameter name, float value)
{
	GLSampler::setSamplerParameter(_samplerID, name, value);
}

void render::Sampler::initSampler()
{
	_samplerID = GLSampler::createSampler();
}

void render::Sampler::releaseSampler()
{
	GLSampler::deleteSampler(_samplerID);
	_samplerID = 0;
}

