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
	public:
		// 添加纹理集
		void addTexAtlas(const std::string& imagePath, const std::string& atlasPath, const sys::ImageTextureAtlas& texAtlas);
		// 添加纹理集
		void addTexAtlas(const std::string& imagePath, const std::string& atlasPath, const Texture* texture, const sys::ImageTextureAtlas& texAtlas);
		// 获取字符纹理名称, preload是否预加载
		std::string getFrameName(const std::string& atlasPath, const std::string& name, bool preload = true);
		// 获取图集
		const sys::ImageTextureAtlas* getTexAtlas(const std::string& atlasPath) const;
		// 移除纹理集
		void removeTexAtlas(const std::string& atlasPath);
		// 是否包含纹理集
		bool containsTexAtlas(const std::string& atlasPath) const;
	public:
		// 添加
		void addTexFrame(const std::string& atlasPath, const TexFrame* texFrame, bool cleanup = true);
		// 添加
		void addTexFrame(const std::string& atlasPath, const Texture* texture,
			const std::string& name, const math::Rect& rect, bool rotate = false, bool cleanup = true);
		// 获取纹理碎片
		const TexFrame* getTexFrame(const std::string& atlasPathName, bool preload = true);
		// 获取纹理碎片
		const TexFrame* getTexFrame(const std::string& atlasPath, const std::string name, bool preload = true);
		// 移除纹理碎片
		void removeTexFrame(const std::string& atlasPathName);
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
		// 获取字符纹理名称, preload是否预加载
		std::string _getFrameName(const std::string& atlasPath, const std::string& name) const;
		// 获取纹理碎片
		const TexFrame* _getTexFrame(const std::string& atlasPathName) const;
		// 预加载纹理碎片
		void _preloadTexFrame(const std::string& atlasPath, const std::string& name);
	private:
		// 缓存的2d纹理
		std::map<std::string, Texture2D*> _texture2Ds;
		// 缓存的纹理
		std::map<uint32_t, Texture*> _textures;
		// 缓存的纹理集,{图集配置名称[纹理名称], 纹理信息}
		std::map<std::string, TexFrame*> _texAtlasFrames;
		// 缓存的纹理集配置,{图集配置名称, 纹理信息}
		std::map<std::string, sys::ImageTextureAtlas> _texAtlas;
	};

	#define G_TEXTURE_CACHE sys::Instance<render::TextureCache>::getInstance()
}