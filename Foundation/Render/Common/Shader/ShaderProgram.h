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
	*	管线处理：
	*	1.顶点着色器
	*	2.细分和几何着色器
	*	3.将几何体装配为图元送入光栅化
	*	4.片源经过处理，作为像素进入帧缓存中
	*
	*	片元源处理
	*	1.剪切测试
	*	2.多重采样的片元操作
	*	3.模板测试
	*	4.深度测试
	*	5.融混
	*	6.逻辑操作
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
		uint32_t getProgramID() const;
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
		*	关联片元着色器中颜色输出位置
		*/
		void bindFragDataLocation(uint32_t colorNumber, const char* name);
		/**
		*	关联片元着色器中颜色输出位置
		*/
		void bindFragDataLocationIndexed(uint32_t colorNumber, uint32_t index, const char* name);
	public:
		/**
		*	链接
		*/
		bool link();
		/**
		*	调用
		*/
		void use();
		/**
		*	是否有效
		*/
		bool isValid() const;
		/**
		*	验证是否有效
		**/
		bool validate();
	public:
		
		/**
		*	从文件加载shader
		*/
		bool loadShaderFromFile(ShaderType type, const std::string& path);
	public:
		/**
		*	设置成可分离
		*/
		void setSeparable(bool value);
	public:
		/**
		*	绑定属性
		*/
		void bindAttrib(uint32_t index, const std::string& name);
		/**
		*	获取属性
		*/
		ShaderAttrib* getAttrib(const std::string& name);
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
		void addAttrib(const std::string& name, ShaderAttrib* attrib);
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
		void removeAllAttribs();
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
		void unuse();
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