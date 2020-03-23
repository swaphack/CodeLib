#pragma once

#include "system.h"
#include <map>
#include <string>

#include "Resource/Config/ImageDefine.h"
#include "Resource/Config/TextDefine.h"

namespace render
{
	struct ImageDefine;
	struct TextDefine;
	class Texture;
	class Texture2D;

	// �����
	class TextureCache
	{
	public:
		TextureCache();
		~TextureCache();
	public:
		// �������
		void addTexture(const std::string& path, Texture* texture);
		// �Ƴ�����
		void removeTexture(Texture* texture);
		// �Ƴ�����
		void removeTexture(const std::string& path);
		// �Ƴ���������
		void removeAllTextures();
		// ��ȡ����
		Texture* getTexture(const std::string& path);
	public:
		// ���һ��2d����
		Texture2D* createTexture2D(const ImageDefine& imageDefine);
		// ���һ��2d����
		Texture2D* createTexture2D(const std::string& path);
		// ���һ���ı�����
		Texture2D* createTexture2D(const TextDefine& textDefine);
	private:
		std::map<std::string, Texture*> _textures;
	};

	#define G_TEXTURE_CACHE sys::Instance<TextureCache>::getInstance()
}