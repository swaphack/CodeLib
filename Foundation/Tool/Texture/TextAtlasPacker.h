#pragma once

#include <string>
#include <set>
#include <map>

#include "AtlasPacker.h"

namespace tool
{
	// 文本纹理打包工具
	class TextAtlasPacker : public AtlasPacker
	{
	public:
		TextAtlasPacker();
		~TextAtlasPacker();
	public:
		/**
		*	加载图片信息
		*/
		void setText(const std::string& content, const std::string& fontFilePath, int fontSize);
	public:
		/**
		*	加载图片信息
		*/
		void loadTextDetails(std::map<std::string, sys::ImageDetail*>& mapDetails);
		/**
		*	打包成png
		*/
		bool packImage(const std::string& imgFilePath, const std::string& atlasFilePath);
	private:
		sys::TextDefine _textDefine;
	};
}