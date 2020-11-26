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

	// �����
	class TextureCache
	{
	public:
		TextureCache();
		~TextureCache();
	public:
		// �������
		void addTexture2D(const std::string& path, Texture2D* texture);
		// �Ƴ�����
		void removeTexture(Texture* texture);
		// �Ƴ�����
		void removeTexture2D(const std::string& path);
		// �Ƴ���������
		void removeAllTextures();
		// ��ȡ����
		Texture2D* getTexture2D(const std::string& path);
	public:
		// ����һ��2d����
		Texture2D* createTexture2D(const phy::Color4B& color);
		// ����һ��2d����
		Texture2D* createTexture2D(const sys::ImageDefine& imageDefine);
		// ����һ��2d����
		Texture2D* createTexture2D(const std::string& path);
		// ����һ���ı�����
		Texture2D* createTexture2D(const sys::TextDefine& textDefine);
		// ����һ������������
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