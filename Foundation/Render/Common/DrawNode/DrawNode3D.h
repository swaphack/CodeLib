#pragma once

#include "DrawNode.h"
#include "Common/struct/vertex_common.h"

namespace render
{
	/**
	*	3d����
	*/
	class DrawNode3D : 
		public DrawNode
	{
	public:
		DrawNode3D();
		virtual ~DrawNode3D();
	public:
		// ��ص��ã����������޸�ʱ֪ͨ
		virtual bool init();
	protected:
		/**
		*	��״�ı�
		*/
		void onDrawNode3DBodyChange();
		/**
		*	��ɫ�ı�
		*/
		void onDrawNode3DColorChange();
		/**
		*	����ı�
		*/
		virtual void onDrawNode3DTextureChange();
		/**
		*	���½ڵ���Ϣ
		*/
		virtual void updateDrawNode3DMesh();
	protected:
		virtual void afterDraw();
	protected:
		// ������Ϣ
		CubeVertex _cubeVertex;
	};
}