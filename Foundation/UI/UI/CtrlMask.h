#pragma once

#include "CtrlWidget.h"

namespace ui
{
	/**
	*	узуж
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
		*	Джх╬╫з╣Ц
		*/
		virtual render::DrawNode2D* getRenderNode();
	protected:
		virtual void onColorChange();
	private:
		render::Mask* _maskNode = nullptr;
	};
}