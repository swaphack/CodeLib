#pragma once

#include "Base/Instance.h"
#include "TextDefine.h"
namespace sys
{
	class FaceLibrary;
	class LabelStream;

	/**
	*	文本库
	*/
	class LabelLibrary
	{
	public:
		LabelLibrary();
		~LabelLibrary();
	public:
		// 加载文本
		bool load(const TextDefine& textDefine, LabelStream* stream);
		// 清空
		void cleanup();
	protected:
		void init();
		// 获取字体库
		FaceLibrary* getFontLibrary(const std::string& filepath, int size);

		void dispose();
	private:
		void*  _library = nullptr;
		// 字体库
		std::map<std::string, std::map<int, FaceLibrary*>> _fontLibs;
	};

#define G_FONT_LIB sys::Instance<sys::LabelLibrary>::getInstance()
}