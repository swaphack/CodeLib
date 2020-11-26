#pragma once

#include "system.h"
#include <map>
#include <string>

#include "physicslib.h"

namespace sys
{
	struct ImageDefine;
	struct TextDefine;
}

namespace render
{
	class Texture;
	class Texture2D;
	class TextureCubeMap;

	// 纹理池
	class TextureCache
	{
	public:
		TextureCache();
		~TextureCache();
	public:
		// 添加纹理
		void addTexture2D(const std::string& path, Texture2D* texture);
		// 移除纹理
		void removeTexture(Texture* texture);
		// 移除纹理
		void removeTexture2D(const std::string& path);
		// 移除所有纹理
		void removeAllTextures();
		// 获取纹理
		Texture2D* getTexture2D(const std::string& path);
	public:
		// 创建一个2d纹理
		Texture2D* createTexture2D(const phy::Color4B& color);
		// 创建一个2d纹理
		Texture2D* createTexture2D(const sys::ImageDefine& imageDefine);
		// 创建一个2d纹理
		Texture2D* createTexture2D(const std::string& path);
		// 创建一个文本纹理
		Texture2D* createTexture2D(const sys::TextDefine& textDefine);
		// 创建一个立方体纹理
		TextureCubeMap* createTextureCubeMap(int count, const std::string* images);
	public:
		sys::ImageDetail* loadImageDetail(const std::string& path);

		sys::ImageDetail* loadImageDetail(const sys::ImageDefine& imageDefine);
	private:
		std::map<std::string, Texture2D*> _texture2Ds;

		std::map<uint32_t, Texture*> _textures;
	};

	#define G_TEXTURE_CACHE sys::Instance<render::TextureCache>::getInstance()
}