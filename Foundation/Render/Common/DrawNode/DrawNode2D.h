#pragma once

#include "DrawNode.h"
#include "Common/struct/shape_common.h"
#include "Common/struct/vertex_common.h"
#include "DrawBoxProtocol.h"
namespace render
{
	/**
	*	2d����
	*/
	class DrawNode2D : 
		public DrawNode, 
		public DrawBoxProtocol

	{
	public:
		DrawNode2D();
		virtual ~DrawNode2D();
	public:
		virtual bool init();
	public:
		/**
		*	�Ƿ���ʾ����
		*/
		void setMeshVisible(bool bVisible);
		/**
		*	�Ƿ���ʾ����
		*/
		bool isMeshVisible() const;
	public:
		/**
		*	��ȡ���ؾ��ο�
		*/
		const RectPoints& getLocalRectVertex() const;
		/**
		*	��ȡ������ο�
		*/
		const RectPoints& getWorldRectVertex() const;
		/**
		*	�����Ƿ��ڵ�ǰ������
		*/
		virtual bool containPoint(const math::Vector2& touchPoint);
	protected:
		/**
		*	����ʵ�ʾ��ο�����
		*/
		void calRealRectPoints();
		/**
		*	��״�ı�
		*/
		void onDrawNode2DBodyChange();
		/**
		*	��ɫ�ı�
		*/
		void onDrawNode2DColorChange();
		/**
		*	����ı�
		*/
		void onDrawNode2DTextureChange();
		/**
		*	���ƾ���
		*/
		void drawRect();
		/**
		*	����2d�ڵ���Ϣ
		*/
		void updateDrawNode2DMesh();
	protected:
		virtual void afterDraw();
	protected:
		// �Ƿ���ʾ����
		bool _bMeshVisible = false;
		// ���ؾ��ο�
		RectPoints _localRectPoints;
		// ������ο�
		RectPoints _worldRectPoints;
		// ��������
		RectVertex _rectVertex;
	};
}
