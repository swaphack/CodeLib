#pragma once

#include "Panel.h"

namespace ue
{
	/**
	*	获取文档面板
	*/
	class DocumentPanel : public Panel
	{
	public:
		DocumentPanel();
		virtual ~DocumentPanel();
	public:
		virtual bool init();
	public:


	protected:
		/**
		*	初始化
		*/
		virtual void initUI();
		/**
		*	事件绑定
		*/
		virtual void initEvent();
		/**
		*	初始化文本
		*/
		virtual void initText();
	};
}
