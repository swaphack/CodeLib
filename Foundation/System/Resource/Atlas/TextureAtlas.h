#pragma once

#include <string>
#include <map>
#include <vector>

#include "Framework/Object.h"

namespace sys
{

	/**
	*	纹理碎片
	*/ 
	class TextureChip : public Object
	{
	public:
		std::string name;
		int width = 0;
		int height = 0;
		int x = 0;
		int y = 0;
		bool rotate = false;
	};
	/**
	*	纹理集
	*/
	class TextureAtlas
	{
	public:
		TextureAtlas();
		virtual ~TextureAtlas();
	public:
		/**
		*	图片路径
		*/
		void setImagePath(const std::string& imgFilePath);
		/**
		*	图片路径
		*/
		const std::string& getImagePath() const;
		/**
		*	纹理配置路径
		*/
		void setAtlasPath(const std::string& atlasFilePath);
		/**
		*	纹理配置路径
		*/
		const std::string& getAltasPath() const;
	private:
		// 纹理集配置路径
		std::string _atlasFilePath;
		// 图片路径
		std::string _imgFilePath;
	};
}
