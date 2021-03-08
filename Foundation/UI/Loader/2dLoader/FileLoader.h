#pragma once

#include "WidgetLoader.h"
#include "Display/CtrlFile.h"

namespace ui
{
	// �ļ����ؿؼ�
	class FileLoader : public WidgetLoader
	{
	public:
		FileLoader();
		virtual ~FileLoader();
	protected:
		// ��������
		virtual void parseAttributes();
		// ��������
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, CtrlFile, ELEMENT_NAME_FILE);
	};

	// �ؼ�
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