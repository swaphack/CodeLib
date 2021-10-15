#pragma once

#include <string>
#include <map>
#include <vector>

namespace sys
{

	/**
	*	纹理碎片
	*/ 
	struct TextureChip
	{
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
		~TextureAtlas();
	public:
		/**
		*	图片路径
		*/
		void setImage(const std::string& imgFilePath);
		/**
		*	图片路径
		*/
		const std::string& getImagePath() const;
		/**
		*	纹理配置路径
		*/
		void setAltasPath(const std::string& altasFilePath);
		/**
		*	纹理配置路径
		*/
		const std::string& getAltasPath() const;
	public:
		/**
		*	添加纹理碎片
		*/
		void addChip(const std::string& name, int width, int height, int x, int y, bool rotate = false);
		/**
		*	添加纹理碎片
		*/
		void addChip(const TextureChip& chip);
		/**
		*	移除纹理碎片
		*/
		void removeChip(const std::string& name);
		/**
		*	查找纹理碎片
		*/
		const TextureChip* getChip(const std::string& name) const;
		/**
		*	移除所有纹理碎片
		*/
		void removeAllChips();
		/**
		*	获取所有纹理碎片
		*/
		const std::map<std::string, TextureChip>& getAllChips() const;
	private:
		// 碎片
		std::map<std::string, TextureChip> _chips;
		// 纹理集配置路径
		std::string _altasFilePath;
		// 图片路径
		std::string _imgFilePath;
	};
}
