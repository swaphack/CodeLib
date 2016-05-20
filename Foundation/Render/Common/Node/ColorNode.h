#pragma once

#include "Node.h"

namespace render
{
	// 带有颜色的节点
	class ColorNode :  public Node, public ColorProtocol
	{
	public:
		ColorNode();
		virtual ~ColorNode();
	public:
		virtual void draw();
		// 设置混合条件
		void setBlend(int src, int dest);
		// 获取混合参数
		const BlendParam& getBlend();
	protected:
		// 混合参数
		BlendParam _blend;
	};
}