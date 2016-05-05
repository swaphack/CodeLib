#pragma once

#include "macros.h"

namespace render
{
	// ����
	class CtrlMask : public ColorNode
	{
	public:
		CtrlMask();
		virtual ~CtrlMask();
	public:
		virtual void draw();

		// ���ò�͸����
		void setOpacity(uchar opacity);
		// ���ò�͸����
		uchar getOpacity();
	protected:
	private:
		uchar _opacity;
	};
}