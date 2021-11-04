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
		void addTexAtlas(const std::string& imagePath, const std::string& atlasPath, const sys::FontTextureAtlas& texAtlas);
		// �������
		void addTexAtlas(const std::string& imagePath, const std::string& atlasPath, const Texture* texture, const sys::FontTextureAtlas& texAtlas);
		// ��ȡ����ͼ��
		const sys::FontTextureAtlas* getFontAtlas(const std::string& atlasPath) const;
		// ��ȡ�ַ�����
		const sys::FontTextureChip* getCharData(const std::string& atlasPath, uint64_t ch) const;
		// ��ȡ�ַ�����
		const sys::FontTextureChip* getCharData(const std::string& atlasPath, const std::string& name) const;
		// ��ȡ�ַ���������, preload�Ƿ�Ԥ����
		std::string getAtlasName(const std::string& atlasPath, const std::string& name, bool preload = true);
		// ��ȡ����
		std::string getCharName(uint64_t ch) const;
	private:
		// Ԥ����������Ƭ
		void _preloadTexFrame(const std::string& atlasPath, const std::string& name);
	private:
		// ����ͼ��
		std::map<std::string, sys::FontTextureAtlas> _fontAtlas;
	};


#define G_TEXT_CACHE sys::Instance<render::TextCache>::getInstance()
}
