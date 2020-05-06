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
	*	��ɫ�����Ƴ���
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
		*	������
		*/
		uint32_t getProgramID();
	public:
		/**
		*	������ɫ��
		*/
		void attachShader(Shader* shader);
		/**
		*	ȡ����ɫ���Ĺ���
		*/
		void detachShader(Shader* shader);
		/**
		*	ȡ��������ɫ���Ĺ���
		*/
		void detachAllShaders();
	public:
		/**
		*	����
		*/
		void link();
		/**
		*	����
		*/
		void use();
		/**
		*	�Ƿ���Ч
		*/
		bool isValid();
	public:
		/**
		*	����ļ� v ���㣬 fƬԪ
		*/
		bool loadVertexAndFragmentShader(const std::string& vpath, const std::string& fpath);
		/**
		*	�����ļ�
		*/
		bool loadFromFile(ShaderType type, const std::string& path);
	public:
		/**
		*	���óɿɷ���
		*/
		void setSeparable(bool value);
	public:
		/**
		*	��ȡ����
		*/
		ShaderAttrib* getAttriubte(const std::string& name);
		/**
		*	��ȡ�̶�����
		*/
		ShaderUniform* getUniform(const std::string& name);
		/**
		*	��ȡ���Կ�
		*/
		ShaderUniformBlock* getUniformBlock(const std::string& name);
		/**
		*	�ӳ���
		*/
		ShaderSubroutineUniform* getSubroutineUniform(ShaderType shaderType, const std::string& name);
		/**
		*	����
		*/
		ShaderProgramPipeline* getShaderProgramPipeline(uint32_t tags, const std::string& name);
		/**
		*	��ȡ�ɱ������
		*/
		ShaderProgramUniform* getProgramUniform(const std::string& name);
	protected:
		/**
		*	�������
		*/
		void addAttriubte(const std::string& name, ShaderAttrib* attrib);
		/**
		*	��ӹ̶�����
		*/
		void addUniform(const std::string& name, ShaderUniform* uniform);
		/**
		*	��ӹ̶�����
		*/
		void addUniformBlock(const std::string& name, ShaderUniformBlock* uniform);
		/**
		*	��ӹ̶�����
		*/
		void addSubroutineUniform(const std::string& name, ShaderSubroutineUniform* uniform);
		/**
		*	��ӹ���
		*/
		void addShaderProgramPipeline(const std::string& name, ShaderProgramPipeline* pipeline);
		/**
		*	��ӿɱ������
		*/
		void addProgramUniform(const std::string& name, ShaderProgramUniform* uniform);
	protected:
		/**
		*	�Ƴ���������
		*/
		void removeAllAttributes();
		/**
		*	�Ƴ����й̶�����
		*/
		void removeAllUniforms();
		/**
		*	�Ƴ����й̶�����
		*/
		void removeAllUniformBlocks();
		/**
		*	�Ƴ����й̶�����
		*/
		void removeAllSubroutineUniforms();		
		/**
		*	�Ƴ����й���
		*/
		void removeAllProgramPipelines();
		/**
		*	�Ƴ����пɱ������
		*/
		void removeAllProgramUniforms();
	public:
		/**
		*	������
		*/
		static void useNone();
	protected:
		/**
		*	��ʼ��
		*/
		void initProgram();
		/**
		*	�ͷ�
		*/
		void releaseProgram();
	private:
		/**
		*	������
		*/
		uint32_t _programID = 0;
		/**
		*	��ɫ��
		*/
		std::map<int, Shader*> _shaders;
		/**
		*	����
		*/
		std::map<std::string, ShaderAttrib*> _attributes;
		/**
		*	����
		*/
		std::map<std::string, ShaderUniform*> _uniforms;
		/**
		*	�ɱ������
		*/
		std::map<std::string, ShaderProgramUniform*> _programUniforms;
		/**
		*	���Կ�
		*/
		std::map<std::string, ShaderUniformBlock*> _uniformBlocks;
		/**
		*	�ӳ���
		*/
		std::map<std::string, ShaderSubroutineUniform*> _subroutineUniforms;
		/**
		*	����
		*/
		std::map<std::string, ShaderProgramPipeline*> _programPipelines;
	};

}