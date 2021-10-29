#pragma once
#include "TextureAtlas.h"

namespace sys
{
	/**
	*	纹理碎片
	*/
	class ImageTextureChip : public TextureChip
	{
	public:
	};

	/**
	*	图片纹理集
	*/
	class ImageTextureAtlas : public TextureAtlas
	{
	public:
		ImageTextureAtlas();
		virtual ~ImageTextureAtlas();
	public:
		/**
		*	添加纹理碎片
		*/
		void addChip(const std::string& name, int width, int height, int x, int y, bool rotate = false);
		/**
		*	添加纹理碎片
		*/
		void addChip(const ImageTextureChip* chip);
		/**
		*	移除纹理碎片
		*/
		void removeChip(const std::string& name);
		/**
		*	查找纹理碎片
		*/
		const ImageTextureChip* getChip(const std::string& name) const;
		/**
		*	移除所有纹理碎片
		*/
		void removeAllChips();
		/**
		*	获取所有纹理碎片
		*/
		const std::map<std::string, ImageTextureChip*>& getAllChips() const;
	private:
		// 碎片
		std::map<std::string, ImageTextureChip*> _chips;
	};
}