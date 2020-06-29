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
	*	顶点反馈对象
	*/
	class XFBObject : public Node
	{
	public:
		XFBObject();
		virtual ~XFBObject();
	public:
		/**
		*	加载顶点着色器
		*/
		void loadVertexProgram(const std::string& vertexFilepath);
	public:
		/**
		*	设置输入处理函数
		*/
		void setInputFunc(const XFBProgramFunc& func);
		/**
		*	设置输出处理函数
		*/
		void setOutputFunc(const XFBBufferFunc& func);
		/**
		*	设置缓存大小
		*/
		void setBufferSize(uint32_t size);
		/**
		*	设置绑定对象所在的缓存区域
		*/
		void setTargetBufferRange(int index, uint32_t offset, uint32_t size);
		/**
		*	监听变量
		*/
		void setWatchVaryings(int count, const char** varyings, TransformFeedbackBufferMode mode = TransformFeedbackBufferMode::INTERLEAVED_ATTRIBS);
		/**
		*	基础图形类型
		*/
		void setWatchPrimitiveMode(TransformFeedbackPrimitiveMode mode, uint32_t count = 1);
	protected:
		// 绘制,重写
		virtual void draw();
	protected:
		/**
		*	初始化xfb
		*/
		void initXFB();
		/**
		*	释放xfb
		*/
		void releaseXFB();
	private:
		/**
		*	输入处理函数
		*/
		XFBProgramFunc _inputFunc = nullptr;
		/**
		*	输出处理函数
		*/
		XFBBufferFunc _outputFunc = nullptr;
		/**
		*	计算着色器程序
		*/
		ShaderProgram* _vertexProgram = nullptr;
		/**
		*	顶点反馈
		*/
		TransformFeedback* _transformFeedback = nullptr;
		/**
		*	反馈所存放的缓存
		*/
		TransformFeedbackBuffer* _transformFeedbackBuffer = nullptr;
		/**
		*	缓存大小
		*/
		uint32_t _bufferSize = 0;
		/**
		*	基础图形类型
		*/
		TransformFeedbackPrimitiveMode _primitiveMode = TransformFeedbackPrimitiveMode::POINTS;
		/**
		*	监视大小
		*/
		uint32_t _watchCount = 0;

		bool _hadDraw = false;
	};
}
