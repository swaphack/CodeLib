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
		*	设置图集信息
		*/
		void setAtlas(const std::string& imgFilePath, const std::string& atlasFilePath);
	public:
		/**
		*	图集
		*/
		const sys::ImageTextureAtlas& getTextureAtlas() const;
		/**
		*	图集
		*/
		sys::ImageTextureAtlas& getTextureAtlas();
		/**
		*	加载图集配置
		*/
		void loadTextureAtlas(const std::string& imageFilePath, const std::string& atlasFilePath);
		/**
		*	生成图集配置
		*/
		void saveTextureAtlas(const std::string& atlasFilePath);
	protected:
		/**
		*	保存成png图片和纹理集配置
		*/
		void saveTexAltas(const std::string& imgFilePath, const std::string& atlasFilePath, const std::map<std::string, sys::ImageDetail*>& mapDetails);
		/**
		*	加载图片信息
		*/
		void loadImageDetails(std::map<std::string, sys::ImageDetail*>& mapDetails, const std::string& format = "*.png");
	public:
		/**
		*	打包成png
		*/
		bool packImage(const std::string& imgFilePath, const std::string& atlasFilePath);
	private:
		// 单个图片路径
		std::set<std::string> _images;
		// 图片目录
		std::set<std::string> _dirs;

		// 纹理集
		sys::ImageTextureAtlas _textureAtlas;
	};
}