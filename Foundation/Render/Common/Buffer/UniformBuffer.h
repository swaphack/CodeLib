#pragma once

#include "NoNamedBuffer.h"

namespace render
{
	class ShaderUniformBlockData;

	class UniformBuffer : public NoNamedBuffer
	{
	public:
		UniformBuffer();
		virtual ~UniformBuffer();
	public:
		void setUniformBlockData(const ShaderUniformBlockData* data);
	protected:
	private:
	};
}
