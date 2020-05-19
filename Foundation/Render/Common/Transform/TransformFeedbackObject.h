#pragma once

#include "system.h"
#include <cstdint>
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class BufferObject;
	/**
	*	���㷴������
	*/
	class TransformFeedbackObject : public sys::Object
	{
	public:
		TransformFeedbackObject();
		virtual ~TransformFeedbackObject();
	public:
		uint32_t getTransformFeedbackID() const;
		/**
		*	�Ƿ����
		*/
		bool isValid();
		/**
		*	���û������
		*/
		void setBufferObject(BufferObject* obj);
	public:
		/**
		*	�󶨶��㷴������
		*/
		void bindTransformFeedback();
		/**
		*	���û������
		*/
		void setBufferBase(uint32_t index);
		/**
		*	���û��淶Χ
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
		*	�������
		*/
		BufferObject* _bufferObject = nullptr;
	};
}
