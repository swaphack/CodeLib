#pragma once

#include "NoNamedBufferObject.h"
#include <cstdint>

namespace render
{
	class NoNamedArrayBuffer : public NoNamedBufferObject
	{
	public:
		NoNamedArrayBuffer();
		virtual ~NoNamedArrayBuffer();
	public:
	protected:
	private:
	};

	//////////////////////////////////////////////////////////////////////////
	class NoNamedElemenetArrayBuffer : public NoNamedBufferObject
	{
	public:
		NoNamedElemenetArrayBuffer();
		virtual ~NoNamedElemenetArrayBuffer();
	public:
		void setIndicesData(uint32_t size, const uint32_t* data);
	protected:
	private:
	};

	//////////////////////////////////////////////////////////////////////////
	class ShaderUniformBlockData;
	class NoNamedUniformBuffer : public NoNamedBufferObject
	{
	public:
		NoNamedUniformBuffer();
		virtual ~NoNamedUniformBuffer();
	public:
		void setUniformBlockData(const ShaderUniformBlockData* data);
	protected:
	private:
	};
}