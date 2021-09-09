#pragma once

#include "CtrlWidget.h"

namespace ui
{
	/**
	*	ÕÚÕÖ
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
		*	ÉèÖÃ×ÅÉ«Æ÷
		*/
		virtual void setColorShaderProgram(render::ShaderProgram* shaderProgram);
	protected:
		virtual void onColorChange();
	private:
		render::Mask* _maskNode = nullptr;
	};
}