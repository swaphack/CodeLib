#pragma once

#include "macros.h"

namespace render
{
	/**
	*	ÎÆÀí²ÉÑù
	*/
	class GLSampler
	{
	public:
		static void createSamplers(int n, uint32_t* samplers);
		static uint32_t createSampler();
		static void deleteSamplers(int n, uint32_t* samplers);
		static void deleteSampler(uint32_t id);
	
		static bool isSampler(uint32_t sampler);
	public:
		static void bindSampler(uint32_t unit, uint32_t sampler);
		static void bindSamplers(uint32_t first, int count, const uint32_t* samplers);
	public:
		static void genSamplers(int n, uint32_t* samplers);	
	public:
		static void setSamplerParameter(uint32_t sampler, SamplerParameter name, int value);
		static void setSamplerParameter(uint32_t sampler, SamplerParameter name, float value);
		static void setSamplerParameter(uint32_t sampler, SamplerParameter name, const int* value);
		static void setSamplerParameter(uint32_t sampler, SamplerParameter name, const uint32_t* value);
		static void setSamplerParameter(uint32_t sampler, SamplerParameter name, const float* value);
	public:
		static void getSamplerParameter(uint32_t sampler, SamplerParameter name, float* value);
		static void getSamplerParameter(uint32_t sampler, SamplerParameter name, uint32_t* value);
		static void getSamplerParameter(uint32_t sampler, SamplerParameter name, int* value);
	};
}