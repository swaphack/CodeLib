#pragma once

#include "Common/Buffer/BufferObject.h"
#include "Graphic/GLAPI/macros.h"
namespace render
{
	class ArrayBuffer;
	class VertexArrayAttrib;
	/**
	*	顶点数组对象
	*/
	class VertexArrayObject : public BufferObject
	{
	public:
		VertexArrayObject();
		virtual ~VertexArrayObject();
	public:
		/**
		*	顶点数组编号
		*/
		uint32_t getVAOID() const;
	public:
		/**
		*	是否有效
		*/
		bool isVertexArray();
		/**
		*	绑定
		*/
		void bindVertexArray();
		/**
		*	解除绑定
		*/
		void unbindVertexArray();
	public:
		/**
		*	绑定
		*/
		void bindBuffer();
		/**
		*	绑定
		*/
		void bindBuffer(uint32_t bufferID);
		/**
		*	解除绑定
		*/
		void unbindBuffer();
	public:		
		/**
		*	生成顶点属性指针
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
		*	删除顶点属性指针
		*/
		void removeAllVertexAttribs();
	public:
		/**
		*	使顶点属性指针生效
		*/
		void enableVertexArrayAttrib(uint32_t index);

		/**
		*	使顶点属性指针失效
		*/
		void disableVertexArrayAttrib(uint32_t index);
		/**
		*	设置顶点属性值
		*/
		void setVertexAttribPointer(uint32_t index, uint32_t count, VertexAttribPointerType type, uint32_t stride, uint32_t offset);
	protected:
		/**
		*	生成vao
		*/
		void initVAO();
		/**
		*	释放vao
		*/
		void relaseVAO();
	private:
		/**
		*	编号
		*/
		uint32_t _vaoID = 0;
		/**
		*	调用到的属性
		*/
		std::map<int, VertexArrayAttrib*> _mapVertexAttrib;
	};
}