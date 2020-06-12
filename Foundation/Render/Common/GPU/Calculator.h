#pragma once

#include "Common/Node/Node.h"
#include "Common/Shader/ShaderProgramDelegate.h"

namespace render
{
	
	class ShaderProgram;
	class TransformFeedback;
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
		*	shader设置函数
		*/
		void setProgramFunc(const ShaderProgramFunc& func);
		/**
		*	执行
		*/
		void run();
		/**
		*	文档
		*/
		ShaderDocument* getDocument() const;
	protected:
		void calOutputBuffer();

		void getOutputData();
	private:
		ShaderProgram* _shaderProgram = nullptr;
		/**
		*	xfb对象
		*/
		TransformFeedback* _xfbObject = nullptr;
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