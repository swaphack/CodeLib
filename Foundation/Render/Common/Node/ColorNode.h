#pragma once

#include "Node.h"

namespace render
{
	// ������ɫ�Ľڵ�
	class ColorNode :  public Node, public ColorProtocol
	{
	public:
		ColorNode();
		virtual ~ColorNode();
	public:
		virtual void draw();
		// ���û������
		void setBlend(int src, int dest);
		// ��ȡ��ϲ���
		const BlendParam& getBlend();
	protected:
		// ��ϲ���
		BlendParam _blend;
	};
}