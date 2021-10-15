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
		void addTexture(const std::string& name, const Texture* texture, 
			const std::string& fullpath = "", const math::Rect& rect = math::Rect(0,0,1,1), bool rotate = false);
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
			// ����
			std::string name;
			// ����·��
			std::string fullpath;
			// Ӧ�ô���
			int refCount = 0;
			// ����
			Texture* texture = nullptr;
			// ����
			math::Rect rect = math::Rect(0,0,1,1);
			// �Ƿ���ת
			bool rotate = false;
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
