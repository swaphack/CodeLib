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
	*	������
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
		*	shader���ú���
		*/
		void setProgramFunc(const ShaderProgramFunc& func);
		/**
		*	ִ��
		*/
		void run();
	protected:
		void calOutputBuffer();

		void getOutputData();
	private:
		ShaderProgram* _shaderProgram = nullptr;
		/**
		*	xfb����
		*/
		TransformFeedbackObject* _xfbObject = nullptr;
		/**
		*	xfb��������
		*/
		TransformFeedbackBuffer* _xfbBuffer = nullptr;
		/**
		*	shaderִ�к���
		*/
		ShaderProgramFunc _shaderProgramFunc = nullptr;
		/**
		*	shader�ĵ�
		*/
		ShaderDocument* _document;
	};
}