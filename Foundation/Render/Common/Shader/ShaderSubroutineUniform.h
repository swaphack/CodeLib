#pragma once

#include "ShaderVariable.h"

#include "Graphic/GLAPI/macros.h"

namespace render
{
	/**
	*	�����޸�
	*/
	class ShaderSubroutineUniform : public ShaderVariable
	{
	public:
		ShaderSubroutineUniform();
		virtual ~ShaderSubroutineUniform();
	public:
		/**
		*	���ñ������
		*/
		void setSubUniformID(uint32_t id);
		/**
		*	���Ա��
		*/
		uint32_t getSubUniformID();
	public:
		void setShaderType(ShaderType shaderType);
		ShaderType getShaderType();

		uint32_t getSubroutineIndex(const std::string& name);
		void setSubroutineIndex(uint32_t index);
	private:
		ShaderType _shaderType;
		uint32_t _subUniformID = 0;
	};
}