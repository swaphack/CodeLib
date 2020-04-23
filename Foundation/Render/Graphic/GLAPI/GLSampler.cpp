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

