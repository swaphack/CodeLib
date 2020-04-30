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
		static Shader* create(ShaderType type, const std::string& filepath);
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
		bool loadData(const char* data);
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
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*/
	class TessControlShader : public Shader
	{
	public:
		TessControlShader();
		virtual ~TessControlShader();
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*/
	class TessEvaluationShader : public Shader
	{
	public:
		TessEvaluationShader();
		virtual ~TessEvaluationShader();
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*/
	class ComputeShader : public Shader
	{
	public:
		ComputeShader();
		virtual ~ComputeShader();
	};
}