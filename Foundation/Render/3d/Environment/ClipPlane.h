#pragma once

#include "Common/Node/Node.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	/*
	*	定义一个裁剪平面。
	*	equation参数指向平面方程Ax + By + Cz + D = 0的4个系数。
	*	equation=（0，-1，0,0），前三个参数（0，-1,0）可以理解为法线向下，只有向下的，即Y<0的才能显示，最后一个参数0表示从z=0平面开始。这样就是裁剪掉上半平面。
	*	相应的equation=（0,1,0,0）表示裁剪掉下半平面，
	*	equation=（1,0,0,0）表示裁剪掉左半平面，
	*	equation=（-1,0,0,0）表示裁剪掉右半平面，
	*	equation=（0,0,-1,0）表示裁剪掉前半平面，
	*	equation=（0,0,1,0）表示裁剪掉后半平面
	*/
	class ClipPlane : public Node
	{
	public:
		ClipPlane();
		~ClipPlane();
	public:
		virtual void draw();
		// 获取裁剪平面索引
		virtual ClipPlaneName getClipPlaneName() { return ClipPlaneName::CLIP_PLANE0; }

		// 设置显示面法线方向
		void setClipNormal(float x, float y, float z);
		// 获取显示面法线方向
		math::Vector3 getClipNormal();
	protected:
		// 裁剪平面显示的法线方向
		double _clipNormal[4];
	};

#define CTREATE_CLIPPLANE_CLASS_0(index) \
	class ClipPlane##index : public ClipPlane \
	{ \
	public: \
	virtual ClipPlaneName getClipPlaneName() { return ClipPlaneName::CLIP_PLANE##index; } \
	};

	CTREATE_CLIPPLANE_CLASS_0(0);
	CTREATE_CLIPPLANE_CLASS_0(1);
	CTREATE_CLIPPLANE_CLASS_0(2);
	CTREATE_CLIPPLANE_CLASS_0(3);
	CTREATE_CLIPPLANE_CLASS_0(4);
	CTREATE_CLIPPLANE_CLASS_0(5);
}