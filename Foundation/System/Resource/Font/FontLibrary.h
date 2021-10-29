#pragma once

#include "Base/Instance.h"
#include "TextDefine.h"


namespace sys
{
	class FaceLibrary;
	class LabelStream;
	class ImageDetail;
	class FontCharDetail;

	/**
	*	字体库
	*/
	class FontLibrary
	{
	public:
		FontLibrary();
		~FontLibrary();
	public:
		// 加载文本
		bool load(const TextDefine& textDefine, LabelStream* stream);
		// 加载文本
		bool load(const TextDefine& textDefine, int& lineHeight, std::map<std::string, FontCharDetail*>& mapData);
		// 获取字母信息
		const FontCharDetail* getCharDetail(const std::string& filepath, int size, uint64_t ch);
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

#define G_FONT_LIB sys::Instance<sys::FontLibrary>::getInstance()
}