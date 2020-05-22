#include "GLSampler.h"

using namespace render;

void GLSampler::bindSampler(uint32_t unit, uint32_t sampler)
{
	glBindSampler(unit, sampler);
}

void GLSampler::bindSamplers(uint32_t first, int count, const uint32_t* samplers)
{
	glBindSamplers(first, count, samplers);
}

void GLSampler::createSamplers(int n, uint32_t* samplers)
{
	glCreateSamplers(n, samplers);
}

void GLSampler::deleteSamplers(int n, uint32_t* samplers)
{
	glDeleteSamplers(n, samplers);
}

void render::GLSampler::deleteSampler(uint32_t id)
{
	deleteSamplers(1, &id);
}

void render::GLSampler::setSamplerParameter(uint32_t sampler, SamplerParameter name, const int* value)
{
	glSamplerParameteriv(sampler, (GLenum)name, value);
}

void render::GLSampler::getSamplerParameter(uint32_t sampler, SamplerParameter name, uint32_t* value)
{
	glGetSamplerParameterIuiv(sampler, (GLenum)name, value);
}

void render::GLSampler::getSamplerParameter(uint32_t sampler, SamplerParameter name, int* value)
{
	glGetSamplerParameteriv(sampler, (GLenum)name, value);
}

void render::GLSampler::setSamplerParameter(uint32_t sampler, SamplerParameter name, const uint32_t* value)
{
	glSamplerParameterIuiv(sampler, (GLenum)name, value);
}

void render::GLSampler::setSamplerParameter(uint32_t sampler, SamplerParameter name, float value)
{
	glSamplerParameterf(sampler, (GLenum)name, value);
}

void render::GLSampler::setSamplerParameter(uint32_t sampler, SamplerParameter name, int value)
{
	glSamplerParameteri(sampler, (GLenum)name, value);
}

void GLSampler::genSamplers(int n, uint32_t* samplers)
{
	glGenSamplers(n, samplers);
}

void GLSampler::getSamplerParameter(uint32_t sampler, SamplerParameter name, float* value)
{
	glGetSamplerParameterfv(sampler, (GLenum)name, value);
}

bool GLSampler::isSampler(uint32_t sampler)
{
	return glIsSampler(sampler) == GL_TRUE;
}

void GLSampler::setSamplerParameter(uint32_t sampler, SamplerParameter name, const float* value)
{
	glSamplerParameterfv(sampler, (GLenum)name, value);
}

uint32_t render::GLSampler::createSampler()
{
	uint32_t id;
	createSamplers(1, &id);
	return id;
}

