#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"
#include <map>

namespace render
{
	class Shader;
	class ShaderAttrib;
	class ShaderUniform;
	class ShaderUniformBlock;
	class ShaderSubroutineUniform;
	/**
	*	着色器控制程序
	*	glCreateProgram
	*	{
	*		glAttachShader=>{
    *						 glCreateShader
	*						 glShaderSource
	*						 glShaderCompile
	*						}
	*		glAttachShader
	*		...
	*	}
	*	glLinkProgram
	*	glUseProgram
	*	
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
		uint32_t getProgramID();
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
		ShaderUniformBlock* getUniformBlock(const std::string& name);
	protected:
		/**
		*	添加固定属性
		*/
		void addUniformBlock(const std::string& name, ShaderUniformBlock* uniform);
		/**
		*	移除所有固定属性
		*/
		void removeAllUniformBlocks();
	public:
		ShaderSubroutineUniform* getSubroutineUniform(ShaderType shaderType, const std::string& name);
	protected:
		/**
		*	添加固定属性
		*/
		void addSubroutineUniform(const std::string& name, ShaderSubroutineUniform* uniform);
		/**
		*	移除所有固定属性
		*/
		void removeAllSubroutineUniforms();
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
		void loadVertexAndFragmentShader(const std::string& vpath, const std::string& fpath);
		/**
		*	加载文件
		*/
		void loadFromFile(ShaderType type, const std::string& path);
		/**
		*	加载文件
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<Shader, T>::value, T>::type>
		void loadFromFile(const std::string& path)
		{
			T* pShader = CREATE_OBJECT(T);
			pShader->loadFromFile(path);
			this->attachShader(pShader);
		}
	private:
		/**
		*	程序编号
		*/
		uint32_t _programID = 0;
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
		/**
		*	属性块
		*/
		std::map<std::string, ShaderUniformBlock*> _uniformBlocks;
		/**
		*	子程序
		*/
		std::map<std::string, ShaderSubroutineUniform*> _subroutineUniforms;
	};

}