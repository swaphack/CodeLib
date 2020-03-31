#pragma once

#include "system.h"

#include <map>

namespace render
{
	class Shader;
	class ShaderAttrib;
	class ShaderUniform;
	/**
	*	��ɫ�����Ƴ���
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
		int getProgramID();
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
		void load(const std::string& vpath, const std::string& fpath);
	private:
		/**
		*	������
		*/
		int _programID = 0;
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
	};
}