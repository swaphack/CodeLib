#pragma once

#include <cstdint>
#include "Graphic/GLAPI/macros.h"
#include "Common/Buffer/BufferObject.h"

namespace render
{
	class ShaderProgram;
	class TransformFeedbackBuffer;

	/**
	*	顶点反馈对象
	*/
	class XFBBufferObject : public BufferObject
	{
	public:
		XFBBufferObject();
		virtual ~XFBBufferObject();
	public:
		uint32_t getTransformFeedbackID() const;
		/**
		*	是否可用
		*/
		bool isValid() const;
	public:
		/**
		*	绑定顶点反馈对象
		*/
		void bindTransformFeedback();
		/**
		*	解除顶点反馈对象绑定
		*/
		void unbindTransformFeedback();
		/**
		*	设置缓存对象
		*/
		void setBufferBase(uint32_t index);
		/**
		*	设置缓存范围
		*	@see TransformFeedbackBuffer::setBufferRange
		*	index offset size 
		*/
		void setBufferRange(uint32_t index, ptrdiff_t offset, ptrdiff_t size);
	protected:
		/**
		*	初始化顶点反馈对象
		*/
		void initTransformFeedback();
		/**
		*	释放顶点反馈对象
		*/
		void releaseTransformFeedback();
	private:
		/**
		*	顶点反馈对象编号
		*/
		uint32_t _transformFeedbackID = 0;
		
		/**
		*	着色器程序
		*/
		ShaderProgram* _program = nullptr;
	};
}
