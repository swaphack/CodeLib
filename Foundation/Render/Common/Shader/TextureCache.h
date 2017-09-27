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
		void addTexture(const char* path, Texture* texture);
		// �Ƴ�����
		void removeTexture(Texture* texture);
		// �Ƴ���������
		void removeAllTextures();
		// ��ȡ����
		Texture* getTexture(const char* path);
		// ���һ��2d����
		Texture2D* getTexture2D(const ImageDefine& imageDefine);
		// ���һ���ı�����
		Texture2D* getTexture2D(const TextDefine& textDefine);
	private:
		std::map<std::string, Texture*> _textures;
	};

	#define G_TEXTURE_CACHE sys::Instance<TextureCache>::getInstance()
}