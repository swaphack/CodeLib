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
		static void bindSampler(uint32_t unit, uint32_t sampler);
		static void bindSamplers(uint32_t first, int count, const uint32_t* samplers);

		static void createSamplers(int n, uint32_t* samplers);
		static void deleteSamplers(int n, uint32_t* samplers);

		static void genSamplers(int n, uint32_t* samplers);
		static void getSamplerParameter(uint32_t sampler, SamplerParameter name, float* value);

		static bool isSampler(uint32_t sampler);

		static void setSamplerParameter(uint32_t sampler, SamplerParameter name, const float* value);
	};
}