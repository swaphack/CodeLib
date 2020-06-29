#pragma once

#include "Common/Node/Node.h"

#include "Common/Shader/ShaderProgramDelegate.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class ShaderProgram;
	class TransformFeedback;
	class TransformFeedbackBuffer;
	class VertexArrayObject;
	class ArrayBuffer;

	typedef std::function<void(ShaderProgram* program)> XFBProgramFunc;
	typedef std::function<void(TransformFeedbackBuffer* buffer)> XFBBufferFunc;

	/**
	*	���㷴������
	*/
	class XFBObject : public Node
	{
	public:
		XFBObject();
		virtual ~XFBObject();
	public:
		/**
		*	���ض�����ɫ��
		*/
		void loadVertexProgram(const std::string& vertexFilepath);
	public:
		/**
		*	�������봦����
		*/
		void setInputFunc(const XFBProgramFunc& func);
		/**
		*	�������������
		*/
		void setOutputFunc(const XFBBufferFunc& func);
		/**
		*	���û����С
		*/
		void setBufferSize(uint32_t size);
		/**
		*	���ð󶨶������ڵĻ�������
		*/
		void setTargetBufferRange(int index, uint32_t offset, uint32_t size);
		/**
		*	��������
		*/
		void setWatchVaryings(int count, const char** varyings, TransformFeedbackBufferMode mode = TransformFeedbackBufferMode::INTERLEAVED_ATTRIBS);
		/**
		*	����ͼ������
		*/
		void setWatchPrimitiveMode(TransformFeedbackPrimitiveMode mode, uint32_t count = 1);
	protected:
		// ����,��д
		virtual void draw();
	protected:
		/**
		*	��ʼ��xfb
		*/
		void initXFB();
		/**
		*	�ͷ�xfb
		*/
		void releaseXFB();
	private:
		/**
		*	���봦����
		*/
		XFBProgramFunc _inputFunc = nullptr;
		/**
		*	���������
		*/
		XFBBufferFunc _outputFunc = nullptr;
		/**
		*	������ɫ������
		*/
		ShaderProgram* _vertexProgram = nullptr;
		/**
		*	���㷴��
		*/
		TransformFeedback* _transformFeedback = nullptr;
		/**
		*	��������ŵĻ���
		*/
		TransformFeedbackBuffer* _transformFeedbackBuffer = nullptr;
		/**
		*	�����С
		*/
		uint32_t _bufferSize = 0;
		/**
		*	����ͼ������
		*/
		TransformFeedbackPrimitiveMode _primitiveMode = TransformFeedbackPrimitiveMode::POINTS;
		/**
		*	���Ӵ�С
		*/
		uint32_t _watchCount = 0;

		bool _hadDraw = false;
	};
}
