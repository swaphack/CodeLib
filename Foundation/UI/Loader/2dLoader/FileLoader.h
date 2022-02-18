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
		INIT_LOADER_WIDGET(CtrlFile, ELEMENT_NAME_FILE);
	};

	// 控件
	template<typename FileType>
	class TFileLoader : public FileLoader
	{
		static_assert(std::is_base_of<ui::CtrlFile, FileType>::value, "FileType must inherit from CtrlFile");
	public:
		TFileLoader() 
		{
			PRINT("File Loader Name %s\n", typeid(FileType).name());
		}
		virtual ~TFileLoader() 
		{
		}
	public:
		virtual std::string getName() 
		{ 
			return ELEMENT_NAME_FILE; 
		}
		FileType* getCastWidget() 
		{ 
			return getWidget()->as<FileType>();
		}
		virtual void initWidget() 
		{ 
			_node = render::createNode<FileType>();
		}
	};
}