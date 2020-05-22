#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"
#include "Texture.h"
#include <cstdint>

namespace render
{
	/**
	*	采样器对象
	*/
	class Sampler : public sys::Object
	{
	public:
		Sampler();
		virtual ~Sampler();
	public:
		/**
		*	采样器对象
		*/
		uint32_t getSamplerID() const;
		/**
		*	是否有效
		*/
		bool isValid() const;
	public:
		/**
		*	绑定纹理单元
		*	@see ActiveTextureName
		*	纹理：ActiveTextureName::TEXTURE0 + unit;
		*	
		*/
		void bind(uint32_t unit);
		/**
		*	设置参数
		*/
		void setParameter(SamplerParameter name, int value);
		/**
		*	设置参数
		*/
		void setParameter(SamplerParameter name, float value);
		/**
		*	设置参数
		*/
		void setParameter(SamplerParameter name, const int* value);
		/**
		*	设置参数
		*/
		void setParameter(SamplerParameter name, const uint32_t* value);
		/**
		*	设置参数
		*/
		void setParameter(SamplerParameter name, const float* value);
		/**
		*	设置参数
		*/
		void apply(const TextureSetting& setting);
	protected:
		/**
		*	生成采样器
		*/
		void initSampler();
		/**
		*	释放采样器
		*/
		void releaseSampler();
	private:
		/**
		*	采样器对象
		*/
		uint32_t _samplerID = 0;
	};
}