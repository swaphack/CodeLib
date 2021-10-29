#pragma once

#include "system.h"

namespace render
{
	class Texture;

	class TextCache
	{
	public:
		TextCache();
		virtual~TextCache();
	public:
		// �������
		void addTexAtlas(const std::string& path, const sys::FontTextureAtlas& texAtlas);
		// �������
		void addTexAtlas(const std::string& path, const Texture* texture, const sys::FontTextureAtlas& texAtlas);
		// ��ȡ����ͼ��
		const sys::FontTextureAtlas* getFontAtlas(const std::string& filepath) const;
		// ��ȡ�ַ�����
		const sys::FontTextureChip* getCharData(const std::string& filepath, uint64_t ch) const;
	private:
		// ����ͼ��
		std::map<std::string, sys::FontTextureAtlas> _fontAtlas;
	};


#define G_TEXT_CACHE sys::Instance<render::TextCache>::getInstance()
}
