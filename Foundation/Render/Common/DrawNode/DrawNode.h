#pragma once

#include "../Node/Node.h"

namespace render
{
	class Material;
	class Mesh;
	class FragmentOperator;

	/**
	*	绘制节点
	*/
	class DrawNode :  
		public Node
	{
	public:
		DrawNode();
		virtual ~DrawNode();
	public:
		virtual bool init();
		virtual void draw();
	public:
		/** 
		*	材质
		*/
		Material* getMaterial();
		/**
		*	网格
		*/
		Mesh* getMesh();
		/**
		*	片元处理
		*/
		FragmentOperator* getFragOperator();
	protected:
		/**
		*	绘制前工作
		*/
		void beforeDraw();
		/**
		*	绘制
		*/
		virtual void onDraw();
		/**
		*	绘制后工作
		*/
		void afterDraw();
	protected:
		/**
		*	使用客户端数组绘制
		*/
		void drawWithClientArray();
		/**
		*	使缓存对象绘制
		*/
		void drawWithBufferObject();
	protected:
		// 材质
		Material* _material = nullptr;
		// 网格
		Mesh* _mesh = nullptr;
		// 片元处理
		FragmentOperator* _fragOperator = nullptr;
	};
}