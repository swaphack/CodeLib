#pragma once

#include "system.h"

namespace render
{
	class ShaderProgram;

	/**
	*	变量
	*/
	class ShaderVariable : public sys::Object
	{
	public:
		ShaderVariable();
		virtual ~ShaderVariable();
	public:
		/**
		*	设置属性名称
		*/
		void setName(const std::string& name);
		/**
		*	属性名称
		*/
		const std::string& getName();
		/**
		*	关联程序
		*/
		void setProgram(ShaderProgram* program);
		/**
		*	关联程序
		*/
		ShaderProgram* getProgram();
		/**
		*	关联程序id
		*/
		uint32_t getProgramID();
	protected:
		/**
		*	名称
		*/
		std::string _name;
		/**
		*	程序
		*/
		ShaderProgram* _program = nullptr;
	};
}