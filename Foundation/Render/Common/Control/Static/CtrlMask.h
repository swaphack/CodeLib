#pragma once

#include "macros.h"

namespace render
{
	// 遮罩
	class CtrlMask : public ColorNode
	{
	public:
		CtrlMask();
		virtual ~CtrlMask();
	public:
		virtual void draw();

		// 设置不透明度
		void setOpacity(uchar opacity);
		// 设置不透明度
		uchar getOpacity();
	protected:
	private:
		uchar _opacity;
	};
}