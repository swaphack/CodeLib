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
		*	设置变量编号
		*/
		void setVarID(int id);
		/**
		*	属性编号
		*/
		int getVarID();
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
	private:
		/**
		*	编号
		*/
		int _varID = 0;
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