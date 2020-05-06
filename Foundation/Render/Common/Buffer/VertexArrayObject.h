#pragma once

#include "system.h"

namespace render
{
	class BufferObject;
	class VAOAttrib;
	/**
	*	�����������
	*/
	class VertexArrayObject : public sys::Object
	{
	public:
		VertexArrayObject();
		virtual ~VertexArrayObject();
	public:
		/**
		*	����������
		*/
		uint32_t getVAOID() const;
	public:
		/**
		*	�Ƿ���Ч
		*/
		bool isVertexArray();
		/**
		*	��
		*/
		void bindVertexArray();
	public:
		/**
		*	��buffer
		*/
		void setBufferObject(BufferObject* buffer);
		/**
		*	��buffer
		*/
		BufferObject* getBufferObject();
		/**
		*	��
		*/
		void bindBuffer();
	public:
		/**
		*	���ɶ�������ָ��
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<render::VAOAttrib, T>::type, T>::value>
		T* getVertexAttrib(uint32_t index)
		{
			auto it = _mapVertexAttrib.find(index);
			if (it != _mapVertexAttrib.end())
			{
				return (T*)it->second;
			}

			T* t = new T(index, this);
			_mapVertexAttrib[Index] = t;
			return t;
		}
		
		/**
		*	ɾ����������ָ��
		*/
		void removeAllVertexAttribs();
	protected:
		/**
		*	����vao
		*/
		void initVAO();
		/**
		*	�ͷ�vao
		*/
		void relaseVAO();
	private:
		/**
		*	���
		*/
		uint32_t _vaoID = 0;
		/**
		*	��buffer
		*/
		BufferObject* _bufferObj = nullptr;
		/**
		*	���õ�������
		*/
		std::map<int, VAOAttrib*> _mapVertexAttrib;
	};
}