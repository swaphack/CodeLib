#pragma once

#include "CtrlWidget.h"

namespace ui
{
	/**
	*	����
	*/
	class CtrlMask :
		public CtrlWidget,
		public render::ColorProtocol
	{
	public:
		CtrlMask();
		virtual ~CtrlMask();
	public:
		virtual bool init();
		/**
		*	��Ⱦ�ڵ�
		*/
		virtual render::DrawNode2D* getRenderNode();
	protected:
		virtual void onColorChange();
	private:
		render::Mask* _maskNode = nullptr;
	};
}