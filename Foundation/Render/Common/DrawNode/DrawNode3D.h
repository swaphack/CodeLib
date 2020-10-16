#pragma once

#include "DrawNode.h"
#include "Common/struct/shape_common.h"
#include "Common/struct/vertex_common.h"

namespace render
{
	/**
	*	3d����
	*/
	class DrawNode3D : public DrawNode
	{
	public:
		DrawNode3D();
		virtual ~DrawNode3D();
	public:
		// ��ص��ã����������޸�ʱ֪ͨ
		virtual bool init();
	public:
		/**
		*	�Ƿ���ʾ���ο�
		*/
		void setBoxVisible(bool bVisible);
		/**
		*	�Ƿ���ʾ���ο�
		*/
		bool isBoxVisible() const;
	public:
		virtual bool containTouchPoint(float x, float y);
	protected:
		void calBoxData();
		/**
		*	����ģ�Ϳ�
		*/
		void drawBox();
	private:
		/**
		*	�Ƿ���ʾ���ο�
		*/
		bool _bBoxVisible = false;
		// ģ�Ϳ�
		CubePoints _boxVertex;
		// ʵ��ģ�Ϳ�
		CubePoints _realBoxVertex;
	};
}