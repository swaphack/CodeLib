#pragma once

#include <cstdint>
#include "Graphic/GLAPI/macros.h"
#include "Common/Buffer/BufferObject.h"

namespace render
{
	class ShaderProgram;
	class TransformFeedbackBuffer;

	/**
	*	���㷴������
	*/
	class XFBBufferObject : public BufferObject
	{
	public:
		XFBBufferObject();
		virtual ~XFBBufferObject();
	public:
		uint32_t getTransformFeedbackID() const;
		/**
		*	�Ƿ����
		*/
		bool isValid() const;
	public:
		/**
		*	�󶨶��㷴������
		*/
		void bindTransformFeedback();
		/**
		*	������㷴�������
		*/
		void unbindTransformFeedback();
		/**
		*	���û������
		*/
		void setBufferBase(uint32_t index);
		/**
		*	���û��淶Χ
		*	@see TransformFeedbackBuffer::setBufferRange
		*	index offset size 
		*/
		void setBufferRange(uint32_t index, ptrdiff_t offset, ptrdiff_t size);
	protected:
		/**
		*	��ʼ�����㷴������
		*/
		void initTransformFeedback();
		/**
		*	�ͷŶ��㷴������
		*/
		void releaseTransformFeedback();
	private:
		/**
		*	���㷴��������
		*/
		uint32_t _transformFeedbackID = 0;
		
		/**
		*	��ɫ������
		*/
		ShaderProgram* _program = nullptr;
	};
}
