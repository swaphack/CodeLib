#pragma once

#include "system.h"
#include "Texture.h"
#include <map>
#include <string>

namespace render
{
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