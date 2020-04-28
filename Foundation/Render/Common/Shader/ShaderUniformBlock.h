#pragma once

#include "ShaderVariable.h"

namespace render
{
	class ShaderUniformBlock : public ShaderVariable
	{
	public:
		ShaderUniformBlock();
		virtual ~ShaderUniformBlock();
	public:
		void initUniformBlock();
	protected:
	private:
	};
}