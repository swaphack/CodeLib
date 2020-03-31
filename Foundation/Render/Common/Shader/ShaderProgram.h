#pragma once

#include "system.h"

#include <map>

namespace render
{
	class Shader;
	class ShaderAttrib;
	class ShaderUniform;
	/**
	*	着色器控制程序
	*/
	class ShaderProgram : public sys::Object
	{
	public:
		ShaderProgram();
		virtual ~ShaderProgram();
	public:
		/**
		*	程序编号
		*/
		int getProgramID();
	public:
		/**
		*	关联着色器
		*/
		void attachShader(Shader* shader);
		/**
		*	取消着色器的关联
		*/
		void detachShader(Shader* shader);
		/**
		*	取消所有着色器的关联
		*/
		void detachAllShaders();
	public:
		/**
		*	获取属性
		*/
		ShaderAttrib* getAttriubte(const std::string& name);
	protected:
		/**
		*	添加属性
		*/
		void addAttriubte(const std::string& name, ShaderAttrib* attrib);
		/**
		*	移除所有属性
		*/
		void removeAllAttributes();
	public:
		/**
		*	获取固定属性
		*/
		ShaderUniform* getUniform(const std::string& name);
	protected:
		/**
		*	添加固定属性
		*/
		void addUniform(const std::string& name, ShaderUniform* uniform);
		/**
		*	移除所有固定属性
		*/
		void removeAllUniforms();
	public:
		/**
		*	调用无
		*/
		static void useNone();
	protected:
		/**
		*	初始化
		*/
		void initProgram();
		/**
		*	释放
		*/
		void releaseProgram();
	public:
		/**
		*	链接
		*/
		void link();
		/**
		*	调用
		*/
		void use();
	public:
		/**
		*	添加文件 v 顶点， f片元
		*/
		void load(const std::string& vpath, const std::string& fpath);
	private:
		/**
		*	程序编号
		*/
		int _programID = 0;
		/**
		*	着色器
		*/
		std::map<int, Shader*> _shaders;
		/**
		*	属性
		*/
		std::map<std::string, ShaderAttrib*> _attributes;
		/**
		*	属性
		*/
		std::map<std::string, ShaderUniform*> _uniforms;
	};
}