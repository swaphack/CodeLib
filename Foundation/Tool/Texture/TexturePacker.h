#pragma once

#include <string>
#include <set>
#include <map>

#include "mathlib.h"
#include "system.h"

namespace tool
{
	// 纹理打包工具
	class TexturePacker
	{
	public:
		TexturePacker();
		~TexturePacker();
	public:
		/**
		*	设置大小
		*/
		void setSize(int width, int height);
		/**
		*	获取宽度
		*/
		int getWidth() const;
		/**
		*	获取高度
		*/
		int getHeight() const;
	public:
		/**
		*	添加图片
		*/
		void addImage(const std::string& filepath);
		/**
		*	移除图片
		*/
		void removeImage(const std::string& filepath);
		/**
		*	移除所有图片
		*/
		void removeAllImages();
	public:
		/**
		*	添加目录
		*/
		void addDirectory(const std::string& filepath);
		/**
		*	移除图片
		*/
		void removeDirectory(const std::string& filepath);
		/**
		*	移除所有图片
		*/
		void removeAllDirectories();
	public:
		const sys::TextureAtlas& getTextureAtlas() const;
		/**
		*	加载图集配置
		*/
		void loadTextureAtlas(const std::string& altasFilePath);
		/**
		*	生成图集配置
		*/
		void saveTextureAtlas(const std::string& altasFilePath);
		/**
		*	打包成png
		*/
		bool packPNG(const std::string& imgFilePath, const std::string& altasFilePath);
	public:
		math::IntSize _size;
		// 单个图片路径
		std::set<std::string> _images;
		// 图片目录
		std::set<std::string> _dirs;
		// 纹理
		sys::TextureAtlas _textureAtlas;
	};
}