#pragma once

#include "system.h"

namespace render
{
	class Texture;

	/**
	*	绘制所需要的纹理缓存
	*/
	class DrawTextureCache : public sys::Object
	{
	public:
		DrawTextureCache();
		virtual ~DrawTextureCache();
	public:
		/**
		*	添加纹理
		*/
		void addTexture(const std::string& name, const std::string& fullpath);
		/**
		*	添加纹理
		*/
		void addTexture(const std::string& name, const Texture* id);
		/**
		*	移除纹理
		*/
		void removeTexture(const std::string& name);
		/**
		*	移除纹理
		*/
		void removeAllTextures();
		/**
		*	获取纹理
		*/
		Texture* getTexture(const std::string& name) const;
	private:
		// 图片纹理
		std::map<std::string, Texture*> _textures;
	};
}
