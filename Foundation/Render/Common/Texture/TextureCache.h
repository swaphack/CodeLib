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
	public:// ����Ƭ��
		std::string getTexFrameName(const std::string& path, const std::string name) const;
		// �������
		void addTexAltas(const std::string& path, const sys::TextureAtlas& texAltas);
		// �������
		void addTexAltas(const std::string& path, const Texture* texture, const sys::TextureAtlas& texAltas);
		// ���
		void addTexFrame(const std::string& path, const TexFrame& texFrame);
		// ���
		void addTexFrame(const std::string& path, const Texture* texture, 
			const std::string& name, const math::Rect& rect);
		// ��ȡ
		const TexFrame* getTexFrame(const std::string& path, const std::string name) const;
		// ��ȡ path[name];
		const TexFrame* getTexFrame(const std::string& pathname) const;
		// �Ƴ�����
		void removeTexFrames(const std::string& path);
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
		// �����2d����
		std::map<std::string, Texture2D*> _texture2Ds;
		// ���������
		std::map<uint32_t, Texture*> _textures;
		// ���������,{ͼƬ����[��������], ������Ϣ}
		std::map<std::string, TexFrame> _texFrames;
	};

	#define G_TEXTURE_CACHE sys::Instance<render::TextureCache>::getInstance()
}