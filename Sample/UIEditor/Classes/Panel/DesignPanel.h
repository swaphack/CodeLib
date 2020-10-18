#pragma once

#include "Panel.h"

namespace ue
{
	// 设计栏
	class DesignPanel : public Panel
	{
	public:
		DesignPanel();
		virtual ~DesignPanel();
	public:
		virtual bool init();
	public:
		/**
		*	设置文件
		*/
		void setUIFile(const std::string& filepath);
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
		//设置文件
		ui::CtrlFile* m_pUIFile = nullptr;
	};
}
