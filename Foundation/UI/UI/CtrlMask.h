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
		*	������ɫ��
		*/
		virtual void setColorShaderProgram(render::ShaderProgram* shaderProgram);
		/**
		*	���������
		*/
		virtual void setCamera(const render::Camera* camera);
		/**
		*	ʹ���������ͷ
		*/
		virtual void setUseDesignCamera(bool bUsed);
	protected:
		virtual void onColorChange();
	private:
		render::Mask* _maskNode = nullptr;
	};
}