#pragma once

#include "Panel/Panel.h"

namespace ue
{
	class UIDesignView;
	class UIDesignProperty;

	// 视图布局
	class UIDesignWindow : public Panel
	{
	public:
		UIDesignWindow();
		virtual ~UIDesignWindow();
	public:
		virtual bool init();
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
	private:
		// 设计面板
		UIDesignView* m_pDesignPanel = nullptr;
	};
}