#pragma once

#include "system.h"

namespace render
{
	class VertexArrayObject;

	/**
	*	��������
	*/
	class VertexArrayAttrib : public sys::Object
	{
	public:
		VertexArrayAttrib(uint32_t index, VertexArrayObject* obj);
		virtual ~VertexArrayAttrib();
	public:
		/**
		*	��������
		*/
		VertexArrayObject* getVAO();
		/**
		*	�������Ա��
		*/
		uint32_t getIndex() const;
	public:
		/**
		*	ʹ��������ָ����Ч
		*/
		void enableVertexArrayAttrib();
		/**
		*	ʹ��������ָ��ʧЧ
		*/
		void disableVertexArrayAttrib();
		/**
		*	ʹ��������������Ч
		*/
		void enableVertexAttribArray();
		/**
		*	ʹ������������ʧЧ
		*/
		void disableVertexAttribArray();
	private:
		uint32_t _index = 0;

		VertexArrayObject* _vaobj = nullptr;
	};
}