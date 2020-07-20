#pragma once

#include "system.h"

namespace render
{
	class Texture;

	/**
	*	��������Ҫ��������
	*/
	class DrawTextureCache : public sys::Object
	{
	public:
		DrawTextureCache();
		virtual ~DrawTextureCache();
	public:
		/**
		*	�������
		*/
		void addTexture(const std::string& name, const std::string& fullpath);
		/**
		*	�������
		*/
		void addTexture(const std::string& name, const Texture* id);
		/**
		*	�Ƴ�����
		*/
		void removeTexture(const std::string& name);
		/**
		*	�Ƴ�����
		*/
		void removeAllTextures();
		/**
		*	��ȡ����
		*/
		Texture* getTexture(const std::string& name) const;
	private:
		// ͼƬ����
		std::map<std::string, Texture*> _textures;
	};
}
