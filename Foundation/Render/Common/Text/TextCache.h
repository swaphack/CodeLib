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
		void addTexAtlas(const std::string& imagePath, const std::string& atlasPath, const sys::FontTextureAtlas& texAtlas);
		// 添加纹理集
		void addTexAtlas(const std::string& imagePath, const std::string& atlasPath, const Texture* texture, const sys::FontTextureAtlas& texAtlas);
		// 获取字体图集
		const sys::FontTextureAtlas* getFontAtlas(const std::string& atlasPath) const;
		// 获取字符数据
		const sys::FontTextureChip* getCharData(const std::string& atlasPath, uint64_t ch) const;
		// 获取字符数据
		const sys::FontTextureChip* getCharData(const std::string& atlasPath, const std::string& name) const;
		// 获取字符纹理名称, preload是否预加载
		std::string getAtlasName(const std::string& atlasPath, const std::string& name, bool preload = true);
		// 获取名字
		std::string getCharName(uint64_t ch) const;
	private:
		// 预加载纹理碎片
		void _preloadTexFrame(const std::string& atlasPath, const std::string& name);
	private:
		// 字体图集
		std::map<std::string, sys::FontTextureAtlas> _fontAtlas;
	};


#define G_TEXT_CACHE sys::Instance<render::TextCache>::getInstance()
}
