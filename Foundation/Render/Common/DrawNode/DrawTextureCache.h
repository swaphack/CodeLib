#pragma once

#include "system.h"

namespace render
{
	class Texture;
	class Node;

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
		*	�ڵ�
		*/
		void setNode(Node* node);
		/**
		*	�ڵ�
		*/
		Node* getNode();
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
			// ����
			Texture* texture = nullptr;
			// ����
			math::Rect rect = math::Rect(0,0,1,1);
			// �Ƿ���ת
			bool rotate = false;
		};
		// ͼƬ���ô���
		std::map<std::string, TextureInfo> _textureInfos;

		// �ڵ�
		Node* _node = nullptr;
	};
}
