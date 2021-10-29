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
		// 纹理集
		const sys::FontTextureAtlas& getTextureAtlas() const;
		/**
		*	加载图集配置
		*/
		void loadTextureAtlas(const std::string& atlasFilePath);
		/**
		*	生成图集配置
		*/
		void saveTextureAtlas(const std::string& atlasFilePath);
	protected:
		/**
		*	保存成png图片和纹理集配置
		*/
		void saveTexAltas(const std::string& imgFilePath, const std::string& atlasFilePath, const std::map<std::string, sys::FontCharDetail*>& mapDetails);
	public:
		/**
		*	打包成png
		*/
		bool packImage(const std::string& imgFilePath, const std::string& atlasFilePath);
	private:
		sys::TextDefine _textDefine;
		// 纹理集
		sys::FontTextureAtlas _textureAtlas;
	};
}