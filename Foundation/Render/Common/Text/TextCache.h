#pragma once

#include "system.h"

namespace render
{
	class Texture;

	class TextCache
	{
	public:
		TextCache();
		virtual~TextCache();
	public:
		// 添加纹理集
		void addTexAtlas(const std::string& path, const sys::FontTextureAtlas& texAtlas);
		// 添加纹理集
		void addTexAtlas(const std::string& path, const Texture* texture, const sys::FontTextureAtlas& texAtlas);
		// 获取字体图集
		const sys::FontTextureAtlas* getFontAtlas(const std::string& filepath) const;
		// 获取字符数据
		const sys::FontTextureChip* getCharData(const std::string& filepath, uint64_t ch) const;
	private:
		// 字体图集
		std::map<std::string, sys::FontTextureAtlas> _fontAtlas;
	};


#define G_TEXT_CACHE sys::Instance<render::TextCache>::getInstance()
}
