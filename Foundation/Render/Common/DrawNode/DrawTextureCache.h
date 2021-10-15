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
		void addTexture(const std::string& name, const Texture* texture, 
			const std::string& fullpath = "", const math::Rect& rect = math::Rect(0,0,1,1), bool rotate = false);
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
		const Texture* getTexture(const std::string& name) const;
		/**
		*	获取纹理
		*/
		Texture* getTexture(const std::string& name);
	private:
		struct TextureInfo
		{
			// 名称
			std::string name;
			// 完整路径
			std::string fullpath;
			// 应用次数
			int refCount = 0;
			// 纹理
			Texture* texture = nullptr;
			// 矩形
			math::Rect rect = math::Rect(0,0,1,1);
			// 是否旋转
			bool rotate = false;
			// 增加引用次数
			void increase();
			// 减少引用次数
			void descrease();
			// 释放
			void dispose();
		};
		// 图片引用次数
		std::map<std::string, TextureInfo> _textureInfos;
	};
}
