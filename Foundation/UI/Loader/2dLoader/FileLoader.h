#pragma once

#include "WidgetLoader.h"
#include "Display/CtrlFile.h"

namespace ui
{
	// 文件加载控件
	class FileLoader : public WidgetLoader
	{
	public:
		FileLoader();
		virtual ~FileLoader();
	protected:
		// 解析属性
		virtual void parseAttributes();
		// 保存属性
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, CtrlFile, ELEMENT_NAME_FILE);
	};

	// 控件
	template<typename FileType, typename = std::enable_if<std::is_base_of<ui::CtrlFile, FileType>::value, FileType>::type>
	class TFileLoader : public FileLoader
	{
	public:
		TFileLoader() {}
		virtual ~TFileLoader() {}
	public:
		INIT_LOADER_WIDGET(LayoutItem, FileType, ELEMENT_NAME_FILE);
	};
}