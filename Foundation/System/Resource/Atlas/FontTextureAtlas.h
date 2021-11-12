#pragma once

#include "TextureAtlas.h"

namespace sys
{
	/**
	*	�ַ�������Ƭ
	*/
	class FontTextureChip : public TextureChip
	{
	public:
		// ʵ�ʱ�׼���-����,���
		int advX = 0;
		int advY = 0;
		// ����ԭ��(0,0)������λͼ��������ص�ˮƽ����.�����������ص���ʽ��ʾ�� 
		int deltaX = 0;
		int deltaY = 0;
	};

	class FontTextureAtlas : public TextureAtlas
	{
	public:
		FontTextureAtlas();
		virtual ~FontTextureAtlas();
	public:
		/**
		*	�ֺŴ�С
		*/
		uint32_t getFontSize() const;
		/**
		*	�ֺŴ�С
		*/
		void setFontSize(uint32_t val);
		/**
		*	�и�
		*/ 
		uint32_t getLineHeight() const;
		/**
		*	�и�
		*/
		void setLineHeight(uint32_t val);
	public:
		/**
		*	���������Ƭ
		*/
		void addChip(const std::string& name, int width, int height, int x, int y, bool rotate = false,
			int advX = 0, int advY = 0, int deltaX = 0, int deltaY = 0);
		/**
		*	���������Ƭ
		*/
		void addChip(const FontTextureChip& chip);
		/**
		*	�Ƴ�������Ƭ
		*/
		void removeChip(const std::string& name);
		/**
		*	����������Ƭ
		*/
		const FontTextureChip* getChip(const std::string& name) const;
		/**
		*	�Ƴ�����������Ƭ
		*/
		void removeAllChips();
		/**
		*	��ȡ����������Ƭ
		*/
		const std::map<std::string, FontTextureChip>& getAllChips() const;
	private:
		// �и�
		uint32_t _lineHeight = 0;
		// �ֺŴ�С
		uint32_t _fontSize = 0;
		// ��Ƭ
		std::map<std::string, FontTextureChip> _chips;
	};
}