#pragma once

#include "Panel/Panel.h"

namespace ue
{
	/**
	*	遮罩层，用于处理事件
	*/
	class UIDesignMask : public Panel
	{
	public:
		UIDesignMask();
		virtual ~UIDesignMask();
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
	protected:
		ui::CtrlWidget* createWidget(const std::string& name);
	private:
		ui::CtrlLayout* m_pMainLayout = nullptr;

		math::Vector2 m_pTempPosition;
		ui::CtrlWidget* m_pCloneWidget = nullptr;
	};
}