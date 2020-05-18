#pragma once

#include "../Node/Node.h"

namespace render
{
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
		Material* getMaterial();
		/**
		*	����
		*/
		Mesh* getMesh();
		/**
		*	ƬԪ����
		*/
		FragmentOperator* getFragOperator();
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
		Material* _material = nullptr;
		// ����
		Mesh* _mesh = nullptr;
		// ƬԪ����
		FragmentOperator* _fragOperator = nullptr;
	};
}