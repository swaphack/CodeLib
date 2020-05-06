#pragma once

#include "system.h"

namespace render
{
	class VertexArrayObject;

	/**
	*	��������
	*/
	class VAOAttrib : public sys::Object
	{
	public:
		VAOAttrib(uint32_t index, VertexArrayObject* obj);
		virtual ~VAOAttrib();
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
	public:
	private:
		uint32_t _index = 0;

		VertexArrayObject* _vaobj = nullptr;
	};
}