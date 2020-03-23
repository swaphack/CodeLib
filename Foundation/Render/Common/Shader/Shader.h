#pragma once

#include "system.h"

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
		int getShaderID();
		/**
		*	��ɫ������
		*/
		int getShaderType();
		/**
		*	������ɫ������
		*/
		void setShaderType(int shaderType);
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
		/** 
		*	��ʾ��־
		*/
		void showLog();
	protected:
	private:
		/**
		*	��ɫ�����
		*/
		int _shaderID = 0;
		/**
		*	��ɫ������
		*/
		int _shaderType = 0;
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