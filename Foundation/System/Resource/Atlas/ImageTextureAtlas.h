#pragma once
#include "TextureAtlas.h"

namespace sys
{
	/**
	*	������Ƭ
	*/
	class ImageTextureChip : public TextureChip
	{
	public:
	};

	/**
	*	ͼƬ����
	*/
	class ImageTextureAtlas : public TextureAtlas
	{
	public:
		ImageTextureAtlas();
		virtual ~ImageTextureAtlas();
	public:
		/**
		*	���������Ƭ
		*/
		void addChip(const std::string& name, int width, int height, int x, int y, bool rotate = false);
		/**
		*	���������Ƭ
		*/
		void addChip(const ImageTextureChip* chip);
		/**
		*	�Ƴ�������Ƭ
		*/
		void removeChip(const std::string& name);
		/**
		*	����������Ƭ
		*/
		const ImageTextureChip* getChip(const std::string& name) const;
		/**
		*	�Ƴ�����������Ƭ
		*/
		void removeAllChips();
		/**
		*	��ȡ����������Ƭ
		*/
		const std::map<std::string, ImageTextureChip*>& getAllChips() const;
	private:
		// ��Ƭ
		std::map<std::string, ImageTextureChip*> _chips;
	};
}