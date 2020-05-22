#pragma once

#include "BufferObject.h"

namespace render
{
	class ArrayBuffer;
	class VertexArrayAttrib;
	/**
	*	�����������
	*/
	class VertexArrayObject : public BufferObject
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
		/**
		*	�����
		*/
		void unbindVertexArray();
	public:
		/**
		*	��
		*/
		void bindBuffer();
	public:		
		/**
		*	���ɶ�������ָ��
		*/
		template<class T, class = std::enable_if<std::is_base_of<VertexArrayAttrib, T>::value, T>::type>
		T* getVertexAttrib(uint32_t index)
		{
			auto it = _mapVertexAttrib.find(index);
			if (it != _mapVertexAttrib.end())
			{
				return (T*)it->second;
			}

			T* t = new T(index, this);
			_mapVertexAttrib[index] = t;
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
		*	���õ�������
		*/
		std::map<int, VertexArrayAttrib*> _mapVertexAttrib;
	};
}