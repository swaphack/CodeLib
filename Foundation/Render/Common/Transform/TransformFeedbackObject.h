#pragma once

#include "system.h"
#include <cstdint>
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class BufferObject;
	/**
	*	顶点反馈对象
	*/
	class TransformFeedbackObject : public sys::Object
	{
	public:
		TransformFeedbackObject();
		virtual ~TransformFeedbackObject();
	public:
		uint32_t getTransformFeedbackID() const;
		/**
		*	是否可用
		*/
		bool isValid();
		/**
		*	设置缓存对象
		*/
		void setBufferObject(BufferObject* obj);
	public:
		/**
		*	绑定顶点反馈对象
		*/
		void bindTransformFeedback();
		/**
		*	设置缓存对象
		*/
		void setBufferBase(uint32_t index);
		/**
		*	设置缓存范围
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
		*	缓存对象
		*/
		BufferObject* _bufferObject = nullptr;
	};
}
