#pragma once

#include "AtlasPacker.h"

namespace tool
{
	// 图片纹理打包工具
	class ImageAtlasPacker : public AtlasPacker
	{
	public:
		ImageAtlasPacker();
		virtual ~ImageAtlasPacker();
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
		*	加载图片信息
		*/
		void loadImageDetails(std::map<std::string, sys::ImageDetail*>& mapDetails, const std::string& format = "*.png");
		/**
		*	打包成png
		*/
		bool packImage(const std::string& imgFilePath, const std::string& atlasFilePath);
	private:
		// 单个图片路径
		std::set<std::string> _images;
		// 图片目录
		std::set<std::string> _dirs;
	};
}