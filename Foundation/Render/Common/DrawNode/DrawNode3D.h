#pragma once

#include "DrawNode.h"
#include "Common/struct/shape_common.h"
#include "Common/struct/vertex_common.h"
#include "DrawBoxProtocol.h"
namespace render
{
	/**
	*	3d����
	*/
	class DrawNode3D : public DrawNode, public DrawBoxProtocol
	{
	public:
		DrawNode3D();
		virtual ~DrawNode3D();
	public:
		// ��ص��ã����������޸�ʱ֪ͨ
		virtual bool init();
	public:
		virtual bool containPoint(const math::Vector2& touchPoint);
	protected:
		void calBoxData();
		/**
		*	����ģ�Ϳ�
		*/
		void drawBox();
	private:
		// ģ�Ϳ�
		CubePoints _boxVertex;
		// ʵ��ģ�Ϳ�
		CubePoints _realBoxVertex;
	};
}