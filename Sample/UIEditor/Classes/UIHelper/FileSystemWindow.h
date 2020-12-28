#pragma once

#include "Panel/SinglePanel.h"

namespace ue
{
	/**
	*  打开文件面板
	*/
	class FileSystemWindow : public SinglePanel
	{
	public:
		FileSystemWindow ();
		virtual ~FileSystemWindow ();
	public:
		/**
		*	文件路径
		*/
		virtual const char* getPanelPath();
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
