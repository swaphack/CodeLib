#pragma once

#include "NoNamedBufferObject.h"

namespace render
{
	class ShaderUniformBlockData;

	class UniformBufferObject : public NoNamedBufferObject
	{
	public:
		UniformBufferObject();
		virtual ~UniformBufferObject();
	public:
		void setUniformBlockData(const ShaderUniformBlockData* data);
	protected:
	private:
	};
}
