#pragma once

#include "CtrlWidget.h"

namespace ui
{
	/**
	*	遮罩
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
		*	设置着色器
		*/
		virtual void setColorShaderProgram(render::ShaderProgram* shaderProgram);
		/**
		*	设置摄像机
		*/
		virtual void setCamera(const render::Camera* camera);
		/**
		*	使用设计摄像头
		*/
		virtual void setUseDesignCamera(bool bUsed);
	protected:
		virtual void onColorChange();
	private:
		render::Mask* _maskNode = nullptr;
	};
}