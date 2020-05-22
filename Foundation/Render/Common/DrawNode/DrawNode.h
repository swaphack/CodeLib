#pragma once

#include "../Node/Node.h"

namespace render
{
	class Materials;
	class Meshes;
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
		Materials* getMaterials();
		/**
		*	网格
		*/
		Meshes* getMeshes();
		/**
		*	片元处理
		*/
		FragmentOperator* getFragOperator();
	public:
		/**
		*	材质
		*/
		Material* getMaterial(int id = 0);
		/**
		*	网格
		*/
		Mesh* getMesh(int id = 0);
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
		Materials* _materiales = nullptr;
		// 网格
		Meshes* _meshes = nullptr;
		// 片元处理
		FragmentOperator* _fragOperator = nullptr;
	};
}