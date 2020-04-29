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
		*	��ȡ����
		*/
		ShaderAttrib* getAttriubte(const std::string& name);
	protected:
		/**
		*	�������
		*/
		void addAttriubte(const std::string& name, ShaderAttrib* attrib);
		/**
		*	�Ƴ���������
		*/
		void removeAllAttributes();
	public:
		/**
		*	��ȡ�̶�����
		*/
		ShaderUniform* getUniform(const std::string& name);
	protected:
		/**
		*	��ӹ̶�����
		*/
		void addUniform(const std::string& name, ShaderUniform* uniform);
		/**
		*	�Ƴ����й̶�����
		*/
		void removeAllUniforms();
	public:
		ShaderUniformBlock* getUniformBlock(const std::string& name);
	protected:
		/**
		*	��ӹ̶�����
		*/
		void addUniformBlock(const std::string& name, ShaderUniformBlock* uniform);
		/**
		*	�Ƴ����й̶�����
		*/
		void removeAllUniformBlocks();
	public:
		ShaderSubroutineUniform* getSubroutineUniform(ShaderType shaderType, const std::string& name);
	protected:
		/**
		*	��ӹ̶�����
		*/
		void addSubroutineUniform(const std::string& name, ShaderSubroutineUniform* uniform);
		/**
		*	�Ƴ����й̶�����
		*/
		void removeAllSubroutineUniforms();
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
	public:
		/**
		*	����
		*/
		void link();
		/**
		*	����
		*/
		void use();
	public:
		/**
		*	����ļ� v ���㣬 fƬԪ
		*/
		void loadVertexAndFragmentShader(const std::string& vpath, const std::string& fpath);
		/**
		*	�����ļ�
		*/
		void loadFromFile(ShaderType type, const std::string& path);
		/**
		*	�����ļ�
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
		*	���Կ�
		*/
		std::map<std::string, ShaderUniformBlock*> _uniformBlocks;
		/**
		*	�ӳ���
		*/
		std::map<std::string, ShaderSubroutineUniform*> _subroutineUniforms;
	};

}