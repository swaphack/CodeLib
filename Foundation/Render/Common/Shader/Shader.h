#pragma once

#include "system.h"

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
		/**
		*	着色器编号
		*/
		int getShaderID();
		/**
		*	着色器类型
		*/
		int getShaderType();
		/**
		*	设置着色器类型
		*/
		void setShaderType(int shaderType);
		/**
		*	加载程序代码
		*/
		void loadData(const char* data);
		/**
		*	从文件加载程序
		*/
		void loadFromFile(const std::string& filepath);
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
		/** 
		*	显示日志
		*/
		void showLog();
	protected:
	private:
		/**
		*	着色器编号
		*/
		int _shaderID = 0;
		/**
		*	着色器类型
		*/
		int _shaderType = 0;
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
	protected:
	private:
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
	protected:
	private:
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
	protected:
	private:
	};
	
}