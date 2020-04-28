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
		/**
		*	��ɫ�����
		*/
		uint32_t getShaderID();
		/**
		*	��ɫ������
		*/
		ShaderType getShaderType();
		/**
		*	������ɫ������
		*/
		void setShaderType(ShaderType shaderType);
		/**
		*	���س������
		*/
		void loadData(const char* data);
		/**
		*	���ļ����س���
		*/
		void loadFromFile(const std::string& filepath);
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
	protected:
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
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	������ɫ��
	*/
	class VertexShader : public Shader
	{
	public:
		VertexShader();
		virtual ~VertexShader();
	protected:
	private:
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	ƬԴ��ɫ��
	*/
	class FragmentShader : public Shader
	{
	public:
		FragmentShader();
		virtual ~FragmentShader();
	protected:
	private:
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	������ɫ��
	*/
	class GeometryShader : public Shader
	{
	public:
		GeometryShader();
		virtual ~GeometryShader();
	protected:
	private:
	};
	
}