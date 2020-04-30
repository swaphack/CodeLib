#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class ShaderProgram;
	/**
	*	着色器
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
		*	着色器编号
		*/
		uint32_t getShaderID();
		/**
		*	着色器类型
		*/
		ShaderType getShaderType();
		/**
		*	设置着色器类型
		*/
		void setShaderType(ShaderType shaderType);
		/**
		*	加载程序代码
		*/
		bool loadData(const char* data);
		/**
		*	从文件加载程序
		*/
		bool loadFromFile(const std::string& filepath);
		/**
		*	从预处理的二进制数据加载程序 spir-v
		*/
		bool loadFromBindary(const void* binary, int length);
		/**
		*	spir-v
		*/
	public:
		/**
		*	初始化
		*/
		void initShader();
		/**
		*	释放
		*/
		void releaseShader();
		/**
		*	关联
		*/
		void attachProgram(ShaderProgram* program);
		/**
		*	取消关联
		*/
		void detachProgram();
	private:
		/**
		*	着色器编号
		*/
		uint32_t _shaderID = 0;
		/**
		*	着色器类型
		*/
		ShaderType _shaderType = ShaderType::VERTEX_SHADER;
		/**
		*	程序
		*/
		ShaderProgram* _program = nullptr;
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	顶点着色器
	*/
	class VertexShader : public Shader
	{
	public:
		VertexShader();
		virtual ~VertexShader();
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	片源着色器
	*/
	class FragmentShader : public Shader
	{
	public:
		FragmentShader();
		virtual ~FragmentShader();
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	几何着色器
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