#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"
#include "Texture.h"
#include <cstdint>

namespace render
{
	/**
	*	����������
	*/
	class Sampler : public sys::Object
	{
	public:
		Sampler();
		virtual ~Sampler();
	public:
		/**
		*	����������
		*/
		uint32_t getSamplerID() const;
		/**
		*	�Ƿ���Ч
		*/
		bool isValid() const;
	public:
		/**
		*	������Ԫ
		*	@see ActiveTextureName
		*	����ActiveTextureName::TEXTURE0 + unit;
		*	
		*/
		void bind(uint32_t unit);
		/**
		*	���ò���
		*/
		void setParameter(SamplerParameter name, int value);
		/**
		*	���ò���
		*/
		void setParameter(SamplerParameter name, float value);
		/**
		*	���ò���
		*/
		void setParameter(SamplerParameter name, const int* value);
		/**
		*	���ò���
		*/
		void setParameter(SamplerParameter name, const uint32_t* value);
		/**
		*	���ò���
		*/
		void setParameter(SamplerParameter name, const float* value);
		/**
		*	���ò���
		*/
		void apply(const TextureSetting& setting);
	protected:
		/**
		*	���ɲ�����
		*/
		void initSampler();
		/**
		*	�ͷŲ�����
		*/
		void releaseSampler();
	private:
		/**
		*	����������
		*/
		uint32_t _samplerID = 0;
	};
}