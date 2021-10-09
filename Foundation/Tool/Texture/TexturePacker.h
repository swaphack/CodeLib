#pragma once

#include "mathlib.h"
#include <string>
#include <set>
#include <map>

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
		/**
		*	生成
		*/
		bool pack(const std::string& filepath);
	public:
		math::IntSize _size;
		// 单个图片路径
		std::set<std::string> _images;
		// 图片目录
		std::set<std::string> _dirs;
	};
}