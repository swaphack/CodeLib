#pragma once

#include "ShaderVariable.h"

#include "Graphic/GLAPI/macros.h"

namespace render
{
	/**
	*	ÊôÐÔÐÞ¸Ä
	*/
	class ShaderSubroutineUniform : public ShaderVariable
	{
	public:
		ShaderSubroutineUniform();
		virtual ~ShaderSubroutineUniform();
	public:
		void setShaderType(ShaderType shaderType);
		ShaderType getShaderType();

		uint32_t getSubroutineIndex(const std::string& name);
		void setSubroutineIndex(uint32_t index);
	private:
		ShaderType _shaderType;
	};
}