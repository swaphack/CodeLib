#pragma once

#include <cstdint>
#include "Graphic/GLAPI/macros.h"
#include "BufferObject.h"

namespace render
{
	class ShaderProgram;
	class TransformFeedbackBuffer;

	/**
	*	顶点反馈对象
	*/
	class TransformFeedbackObject : public BufferObject
	{
	public:
		TransformFeedbackObject();
		virtual ~TransformFeedbackObject();
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
		*	设置缓存对象
		*/
		void setBufferBase(uint32_t index);
		/**
		*	设置缓存范围
		*	@see TransformFeedbackBuffer::setBufferRange
		*	index offset size 
		*/
		void setBufferRange(uint32_t index, ptrdiff_t offset, ptrdiff_t size);
	public:
		/**
		*	设置关联着色器程序
		*/
		void setShaderProgram(ShaderProgram* program);
		/**
		*	获取关联着色器程序
		*/
		ShaderProgram* getShaderProgram() const;
		/**
		*	设置监视参数
		*/
		void setFeedbackVaryings(int count, const char** varyings, TransformFeedbackBufferMode mode);
		/**
		*	开始监视
		*/
		void beginWatch(TransformFeedbackPrimitiveMode mode);
		/**
		*	暂停监视
		*/
		void pauseWatch();
		/**
		*	恢复监视
		*/
		void resumeWatch();
		/**
		*	结束监视
		*/
		void endWatch();
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
