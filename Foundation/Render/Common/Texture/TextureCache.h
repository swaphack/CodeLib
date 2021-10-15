#pragma once

#include "system.h"
#include <map>
#include <string>
#include "TexFrame.h"
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
	public:// 纹理片段
		std::string getTexFrameName(const std::string& path, const std::string name) const;
		// 添加纹理集
		void addTexAltas(const std::string& path, const sys::TextureAtlas& texAltas);
		// 添加纹理集
		void addTexAltas(const std::string& path, const Texture* texture, const sys::TextureAtlas& texAltas);
		// 添加
		void addTexFrame(const std::string& path, const TexFrame& texFrame);
		// 添加
		void addTexFrame(const std::string& path, const Texture* texture, 
			const std::string& name, const math::Rect& rect);
		// 获取
		const TexFrame* getTexFrame(const std::string& path, const std::string name) const;
		// 获取 path[name];
		const TexFrame* getTexFrame(const std::string& pathname) const;
		// 移除纹理集
		void removeTexFrames(const std::string& path);
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
		// 加载图片信息
		sys::ImageDetail* loadImageDetail(const std::string& path);
		// 加载图片信息
		sys::ImageDetail* loadImageDetail(const sys::ImageDefine& imageDefine);
	private:
		// 缓存的2d纹理
		std::map<std::string, Texture2D*> _texture2Ds;
		// 缓存的纹理
		std::map<uint32_t, Texture*> _textures;
		// 缓存的纹理集,{图片名称[纹理名称], 纹理信息}
		std::map<std::string, TexFrame> _texFrames;
	};

	#define G_TEXTURE_CACHE sys::Instance<render::TextureCache>::getInstance()
}