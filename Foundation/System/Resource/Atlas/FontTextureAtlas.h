#pragma once

#include "TextureAtlas.h"

namespace sys
{
	/**
	*	字符纹理碎片
	*/
	class FontTextureChip : public TextureChip
	{
	public:
		// 实际标准面积-步进,宽度
		int advX = 0;
		int advY = 0;
		// 字形原点(0,0)到字形位图最左边象素的水平距离.它以整数象素的形式表示。 
		int deltaX = 0;
		int deltaY = 0;
	};

	class FontTextureAtlas : public TextureAtlas
	{
	public:
		FontTextureAtlas();
		virtual ~FontTextureAtlas();
	public:
		/**
		*	字号大小
		*/
		uint32_t getFontSize() const;
		/**
		*	字号大小
		*/
		void setFontSize(uint32_t val);
		/**
		*	行高
		*/ 
		uint32_t getLineHeight() const;
		/**
		*	行高
		*/
		void setLineHeight(uint32_t val);
	public:
		/**
		*	添加纹理碎片
		*/
		void addChip(const std::string& name, int width, int height, int x, int y, bool rotate = false,
			int advX = 0, int advY = 0, int deltaX = 0, int deltaY = 0);
		/**
		*	添加纹理碎片
		*/
		void addChip(const FontTextureChip& chip);
		/**
		*	移除纹理碎片
		*/
		void removeChip(const std::string& name);
		/**
		*	查找纹理碎片
		*/
		const FontTextureChip* getChip(const std::string& name) const;
		/**
		*	移除所有纹理碎片
		*/
		void removeAllChips();
		/**
		*	获取所有纹理碎片
		*/
		const std::map<std::string, FontTextureChip>& getAllChips() const;
	private:
		// 行高
		uint32_t _lineHeight = 0;
		// 字号大小
		uint32_t _fontSize = 0;
		// 碎片
		std::map<std::string, FontTextureChip> _chips;
	};
}