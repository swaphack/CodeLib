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
	*	���ƽڵ�
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
		*	����
		*/
		Materials* getMaterials();
		/**
		*	����
		*/
		Meshes* getMeshes();
		/**
		*	ƬԪ����
		*/
		FragmentOperator* getFragOperator();
	public:
		/**
		*	����
		*/
		Material* getMaterial(int id = 0);
		/**
		*	����
		*/
		Mesh* getMesh(int id = 0);
	protected:
		/**
		*	����ǰ����
		*/
		void beforeDraw();
		/**
		*	����
		*/
		virtual void onDraw();
		/**
		*	���ƺ���
		*/
		void afterDraw();
	protected:
		/**
		*	ʹ�ÿͻ����������
		*/
		void drawWithClientArray();
		/**
		*	ʹ����������
		*/
		void drawWithBufferObject();
	protected:
		// ����
		Materials* _materiales = nullptr;
		// ����
		Meshes* _meshes = nullptr;
		// ƬԪ����
		FragmentOperator* _fragOperator = nullptr;
	};
}