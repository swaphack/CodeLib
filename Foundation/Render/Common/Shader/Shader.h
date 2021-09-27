#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class ShaderProgram;
	/**
	*	��ɫ��
	*/
	class Shader : public sys::Object
	{
	public:
		Shader();
		virtual ~Shader();
	public:
		static Shader* create(ShaderType type);
		static Shader* createFromData(ShaderType type, const char* data);
		static Shader* createFromFile(ShaderType type, const std::string& filepath);
	public:
		/**
		*	��ɫ�����
		*/
		uint32_t getShaderID() const;
		/**
		*	��ɫ������
		*/
		ShaderType getShaderType() const;
		/**
		*	������ɫ������
		*/
		void setShaderType(ShaderType shaderType);
		/**
		*	���س������
		*/
		bool loadFromData(const char* data);
		/**
		*	���ļ����س���
		*/
		bool loadFromFile(const std::string& filepath);
		/**
		*	��Ԥ����Ķ��������ݼ��س��� spir-v
		*/
		bool loadFromBindary(const void* binary, int length);
		/**
		*	spir-v
		*/
	public:
		/**
		*	��ʼ��
		*/
		void initShader();
		/**
		*	�ͷ�
		*/
		void releaseShader();
		/**
		*	����
		*/
		void attachProgram(ShaderProgram* program);
		/**
		*	ȡ������
		*/
		void detachProgram();

		/**
		*	�Ƿ���Ч
		*/
		bool isValid() const;
	private:
		/**
		*	��ɫ�����
		*/
		uint32_t _shaderID = 0;
		/**
		*	��ɫ������
		*/
		ShaderType _shaderType = ShaderType::VERTEX_SHADER;
		/**
		*	����
		*/
		ShaderProgram* _program = nullptr;
		/**
		*	uniform ����
		*/
		std::set<std::string> _uniformName;
	};
}