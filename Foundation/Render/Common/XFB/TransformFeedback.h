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
	class TransformFeedback : public BufferObject
	{
	public:
		TransformFeedback();
		virtual ~TransformFeedback();
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
	public:
		/**
		*	���ù�����ɫ������
		*/
		void setShaderProgram(ShaderProgram* program);
		/**
		*	��ȡ������ɫ������
		*/
		ShaderProgram* getShaderProgram() const;
		/**
		*	���ü��Ӳ���
		*/
		void setFeedbackVaryings(int count, const char* const* varyings, TransformFeedbackBufferMode mode);
		/**
		*	��ʼ����
		*/
		void beginWatch(TransformFeedbackPrimitiveMode mode);
		/**
		*	��ͣ����
		*/
		void pauseWatch();
		/**
		*	�ָ�����
		*/
		void resumeWatch();
		/**
		*	��������
		*/
		void endWatch();
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