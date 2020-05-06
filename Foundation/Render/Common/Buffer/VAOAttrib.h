#pragma once

#include "system.h"

namespace render
{
	class VertexArrayObject;

	/**
	*	顶点属性
	*/
	class VAOAttrib : public sys::Object
	{
	public:
		VAOAttrib(uint32_t index, VertexArrayObject* obj);
		virtual ~VAOAttrib();
	public:
		/**
		*	所属对象
		*/
		VertexArrayObject* getVAO();
		/**
		*	顶点属性编号
		*/
		uint32_t getIndex() const;
	public:
		/**
		*	使顶点属性指针生效
		*/
		void enableVertexArrayAttrib();
		/**
		*	使顶点属性指针失效
		*/
		void disableVertexArrayAttrib();
		/**
		*	使顶点属性数组生效
		*/
		void enableVertexAttribArray();
		/**
		*	使顶点属性数组失效
		*/
		void disableVertexAttribArray();
	public:
	private:
		uint32_t _index = 0;

		VertexArrayObject* _vaobj = nullptr;
	};
}