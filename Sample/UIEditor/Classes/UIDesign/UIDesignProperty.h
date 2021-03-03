#pragma once
#include "Panel/Panel.h"

namespace ue
{
	class UIPropertyProtocol;

	// 属性栏
	class UIDesignProperty : public Panel
	{
	public:
		UIDesignProperty();
		virtual ~UIDesignProperty();
	public:
		virtual bool init();
	public:
		/**
		*	加载控件
		*/
		void loadWidget(ui::CtrlWidget* pWidget);
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
		// 属性列表
		ui::CtrlListView* m_pListProperty = nullptr;

		// 目标
		ui::CtrlWidget* m_pTargetItem = nullptr;
		UIPropertyProtocol* m_pCurUIProperty = nullptr;
		ui::CtrlWidget* m_pUIFile = nullptr;

		std::map<std::string, UIPropertyProtocol*> m_mapWidgetPropertyProtocol;
	};
}