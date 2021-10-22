#pragma once

#include <string>
#include <set>
#include <map>

#include "mathlib.h"
#include "system.h"

namespace tool
{
	// 纹理打包
	class AtlasPacker
	{
	public:
		AtlasPacker();
		virtual ~AtlasPacker();
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
		/**
		*	y轴反调
		*/
		void setReverseY(bool reverse);
		/**
		*	获取y轴反调
		*/
		bool isReverseY() const;
	public:
		// 纹理集
		const sys::TextureAtlas& getTextureAtlas() const;
	public:
		/**
		*	加载图集配置
		*/
		void loadTextureAtlas(const std::string& atlasFilePath);
		/**
		*	生成图集配置
		*/
		void saveTextureAtlas(const std::string& atlasFilePath);
	public:
		/**
		*	保存成rgba 32位png图片
		*/
		void saveImage(const std::string& imgFilePath, uint8_t* data, sys::ImageDataFormat format = sys::ImageDataFormat::RGBA);
		/**
		*	保存成png图片和纹理集配置
		*/
		void saveTexAltas(const std::string& imgFilePath, const std::string& atlasFilePath, const std::map<std::string, sys::ImageDetail*>& mapDetails);
	protected:
		// 大小
		math::IntSize _size;
		// 纹理集
		sys::TextureAtlas _textureAtlas;
		// y轴是否相反
		bool _reverseY = false;
	};
}