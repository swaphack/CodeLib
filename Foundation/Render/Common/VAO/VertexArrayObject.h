#pragma once

#include "Common/Buffer/BufferObject.h"
#include "Graphic/GLAPI/macros.h"
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
		/**
		*	��
		*/
		void bindBuffer(uint32_t bufferID);
		/**
		*	�����
		*/
		void unbindBuffer();
	public:		
		/**
		*	���ɶ�������ָ��
		*/
		template<class T, class = std::enable_if<std::is_base_of<render::VertexArrayAttrib, T>::value, T>::type>
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
	public:
		/**
		*	ʹ��������ָ����Ч
		*/
		void enableVertexArrayAttrib(uint32_t index);

		/**
		*	ʹ��������ָ��ʧЧ
		*/
		void disableVertexArrayAttrib(uint32_t index);
		/**
		*	���ö�������ֵ
		*/
		void setVertexAttribPointer(uint32_t index, uint32_t count, VertexAttribPointerType type, uint32_t stride, uint32_t offset);
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