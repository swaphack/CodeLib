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
		// �������
		void addTexAtlas(const std::string& imagePath, const std::string& atlasPath, const sys::ImageTextureAtlas& texAtlas);
		// �������
		void addTexAtlas(const std::string& imagePath, const std::string& atlasPath, const Texture* texture, const sys::ImageTextureAtlas& texAtlas);
		// ��ȡ�ַ���������, preload�Ƿ�Ԥ����
		std::string getFrameName(const std::string& atlasPath, const std::string& name, bool preload = true);
		// ��ȡͼ��
		const sys::ImageTextureAtlas* getTexAtlas(const std::string& atlasPath) const;
		// �Ƴ�����
		void removeTexAtlas(const std::string& atlasPath);
		// �Ƿ��������
		bool containsTexAtlas(const std::string& atlasPath) const;
	public:
		// ���
		void addTexFrame(const std::string& atlasPath, const TexFrame* texFrame, bool cleanup = true);
		// ���
		void addTexFrame(const std::string& atlasPath, const Texture* texture,
			const std::string& name, const math::Rect& rect, bool rotate = false, bool cleanup = true);
		// ��ȡ������Ƭ
		const TexFrame* getTexFrame(const std::string& atlasPathName, bool preload = true);
		// ��ȡ������Ƭ
		const TexFrame* getTexFrame(const std::string& atlasPath, const std::string name, bool preload = true);
		// �Ƴ�������Ƭ
		void removeTexFrame(const std::string& atlasPathName);
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
		// ����ͼƬ��Ϣ
		sys::ImageDetail* loadImageDetail(const std::string& path);
		// ����ͼƬ��Ϣ
		sys::ImageDetail* loadImageDetail(const sys::ImageDefine& imageDefine);
	private:
		// ��ȡ�ַ���������, preload�Ƿ�Ԥ����
		std::string _getFrameName(const std::string& atlasPath, const std::string& name) const;
		// ��ȡ������Ƭ
		const TexFrame* _getTexFrame(const std::string& atlasPathName) const;
		// Ԥ����������Ƭ
		void _preloadTexFrame(const std::string& atlasPath, const std::string& name);
	private:
		// �����2d����
		std::map<std::string, Texture2D*> _texture2Ds;
		// ���������
		std::map<uint32_t, Texture*> _textures;
		// ���������,{ͼ����������[��������], ������Ϣ}
		std::map<std::string, TexFrame*> _texAtlasFrames;
		// �������������,{ͼ����������, ������Ϣ}
		std::map<std::string, sys::ImageTextureAtlas> _texAtlas;
	};

	#define G_TEXTURE_CACHE sys::Instance<render::TextureCache>::getInstance()
}