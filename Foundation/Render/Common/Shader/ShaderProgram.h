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
	class ShaderProgramPipeline;
	class ShaderProgramUniform;
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
		*	链接
		*/
		void link();
		/**
		*	调用
		*/
		void use();
		/**
		*	是否有效
		*/
		bool isValid();
	public:
		/**
		*	添加文件 v 顶点， f片元
		*/
		bool loadVertexAndFragmentShader(const std::string& vpath, const std::string& fpath);
		/**
		*	加载文件
		*/
		bool loadFromFile(ShaderType type, const std::string& path);
	public:
		/**
		*	设置成可分离
		*/
		void setSeparable(bool value);
	public:
		/**
		*	获取属性
		*/
		ShaderAttrib* getAttriubte(const std::string& name);
		/**
		*	获取固定属性
		*/
		ShaderUniform* getUniform(const std::string& name);
		/**
		*	获取属性块
		*/
		ShaderUniformBlock* getUniformBlock(const std::string& name);
		/**
		*	子程序
		*/
		ShaderSubroutineUniform* getSubroutineUniform(ShaderType shaderType, const std::string& name);
		/**
		*	管线
		*/
		ShaderProgramPipeline* getShaderProgramPipeline(uint32_t tags, const std::string& name);
		/**
		*	获取可编程属性
		*/
		ShaderProgramUniform* getProgramUniform(const std::string& name);
	protected:
		/**
		*	添加属性
		*/
		void addAttriubte(const std::string& name, ShaderAttrib* attrib);
		/**
		*	添加固定属性
		*/
		void addUniform(const std::string& name, ShaderUniform* uniform);
		/**
		*	添加固定属性
		*/
		void addUniformBlock(const std::string& name, ShaderUniformBlock* uniform);
		/**
		*	添加固定属性
		*/
		void addSubroutineUniform(const std::string& name, ShaderSubroutineUniform* uniform);
		/**
		*	添加管线
		*/
		void addShaderProgramPipeline(const std::string& name, ShaderProgramPipeline* pipeline);
		/**
		*	添加可编程属性
		*/
		void addProgramUniform(const std::string& name, ShaderProgramUniform* uniform);
	protected:
		/**
		*	移除所有属性
		*/
		void removeAllAttributes();
		/**
		*	移除所有固定属性
		*/
		void removeAllUniforms();
		/**
		*	移除所有固定属性
		*/
		void removeAllUniformBlocks();
		/**
		*	移除所有固定属性
		*/
		void removeAllSubroutineUniforms();		
		/**
		*	移除所有管线
		*/
		void removeAllProgramPipelines();
		/**
		*	移除所有可编程属性
		*/
		void removeAllProgramUniforms();
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
		*	可编程属性
		*/
		std::map<std::string, ShaderProgramUniform*> _programUniforms;
		/**
		*	属性块
		*/
		std::map<std::string, ShaderUniformBlock*> _uniformBlocks;
		/**
		*	子程序
		*/
		std::map<std::string, ShaderSubroutineUniform*> _subroutineUniforms;
		/**
		*	管线
		*/
		std::map<std::string, ShaderProgramPipeline*> _programPipelines;
	};

}