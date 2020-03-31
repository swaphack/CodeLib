#pragma once

#include "Common/Node/Node.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	/*
	*	����һ���ü�ƽ�档
	*	equation����ָ��ƽ�淽��Ax + By + Cz + D = 0��4��ϵ����
	*	equation=��0��-1��0,0����ǰ����������0��-1,0���������Ϊ�������£�ֻ�����µģ���Y<0�Ĳ�����ʾ�����һ������0��ʾ��z=0ƽ�濪ʼ���������ǲü����ϰ�ƽ�档
	*	��Ӧ��equation=��0,1,0,0����ʾ�ü����°�ƽ�棬
	*	equation=��1,0,0,0����ʾ�ü������ƽ�棬
	*	equation=��-1,0,0,0����ʾ�ü����Ұ�ƽ�棬
	*	equation=��0,0,-1,0����ʾ�ü���ǰ��ƽ�棬
	*	equation=��0,0,1,0����ʾ�ü������ƽ��
	*/
	class ClipPlane : public Node
	{
	public:
		ClipPlane();
		~ClipPlane();
	public:
		virtual void draw();
		// ��ȡ�ü�ƽ������
		virtual ClipPlaneName getClipPlaneName() { return ClipPlaneName::CLIP_PLANE0; }

		// ������ʾ�淨�߷���
		void setClipNormal(float x, float y, float z);
		// ��ȡ��ʾ�淨�߷���
		math::Vector3 getClipNormal();
	protected:
		// �ü�ƽ����ʾ�ķ��߷���
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