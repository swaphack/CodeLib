#pragma once

#include "system.h"
#include "Texture.h"
#include <map>
#include <string>

namespace render
{
	// 纹理池
	class TextureCache
	{
	public:
		TextureCache();
		~TextureCache();
	public:
		// 添加纹理
		void addTexture(const char* path, Texture* texture);
		// 移除纹理
		void removeTexture(Texture* texture);
		// 移除所有纹理
		void removeAllTextures();
		// 获取纹理
		Texture* getTexture(const char* path);
		// 添加一个2d纹理
		Texture2D* getTexture2D(const ImageDefine& imageDefine);
		// 添加一个文本纹理
		Texture2D* getTexture2D(const TextDefine& textDefine);
	private:
		std::map<std::string, Texture*> _textures;
	};

	#define G_TEXTURE_CACHE sys::Instance<TextureCache>::getInstance()
}