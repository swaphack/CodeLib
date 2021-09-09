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
		void addTexture(const std::string& name, const Texture* texture, const std::string& fullpath = "");
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
		const Texture* getTexture(const std::string& name) const;
		/**
		*	��ȡ����
		*/
		Texture* getTexture(const std::string& name);
	private:
		struct TextureInfo
		{
			std::string name;
			std::string fullpath;
			int refCount = 0;
			Texture* texture = nullptr;
			// �������ô���
			void increase();
			// �������ô���
			void descrease();
			// �ͷ�
			void dispose();
		};
		// ͼƬ���ô���
		std::map<std::string, TextureInfo> _textureInfos;
	};
}
