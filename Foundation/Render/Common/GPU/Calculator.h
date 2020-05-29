#pragma once

#include "Common/Node/Node.h"
#include "Common/Shader/ShaderProgramDelegate.h"

namespace render
{
	class ShaderProgram;
	class TransformFeedbackObject;
	class TransformFeedbackBuffer;
	class ShaderDocument;
	class VertexArrayObject;

	/**
	*	计算器
	*/
	class Calculator : public sys::Object
	{
	public:
		Calculator();
		virtual ~Calculator();
	public:
		/**
		*	shader
		*/
		void setShaderProgram(ShaderProgram* shaderProgram);
		/**
		*	shader
		*/
		ShaderProgram* getShaderProgram();
		/**
		*	shader设置函数
		*/
		void setProgramFunc(const ShaderProgramFunc& func);
		/**
		*	执行
		*/
		void run();
	protected:
		void calOutputBuffer();

		void getOutputData();
	private:
		ShaderProgram* _shaderProgram = nullptr;
		/**
		*	xfb对象
		*/
		TransformFeedbackObject* _xfbObject = nullptr;
		/**
		*	xfb缓存数据
		*/
		TransformFeedbackBuffer* _xfbBuffer = nullptr;
		/**
		*	shader执行函数
		*/
		ShaderProgramFunc _shaderProgramFunc = nullptr;
		/**
		*	shader文档
		*/
		ShaderDocument* _document;
	};
}