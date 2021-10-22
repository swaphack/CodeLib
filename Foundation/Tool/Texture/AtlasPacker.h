#pragma once

#include <string>
#include <set>
#include <map>

#include "mathlib.h"
#include "system.h"

namespace tool
{
	// ������
	class AtlasPacker
	{
	public:
		AtlasPacker();
		virtual ~AtlasPacker();
	public:
		/**
		*	���ô�С
		*/
		void setSize(int width, int height);
		/**
		*	��ȡ���
		*/
		int getWidth() const;
		/**
		*	��ȡ�߶�
		*/
		int getHeight() const;
		/**
		*	y�ᷴ��
		*/
		void setReverseY(bool reverse);
		/**
		*	��ȡy�ᷴ��
		*/
		bool isReverseY() const;
	public:
		// ����
		const sys::TextureAtlas& getTextureAtlas() const;
	public:
		/**
		*	����ͼ������
		*/
		void loadTextureAtlas(const std::string& atlasFilePath);
		/**
		*	����ͼ������
		*/
		void saveTextureAtlas(const std::string& atlasFilePath);
	public:
		/**
		*	�����rgba 32λpngͼƬ
		*/
		void saveImage(const std::string& imgFilePath, uint8_t* data, sys::ImageDataFormat format = sys::ImageDataFormat::RGBA);
		/**
		*	�����pngͼƬ����������
		*/
		void saveTexAltas(const std::string& imgFilePath, const std::string& atlasFilePath, const std::map<std::string, sys::ImageDetail*>& mapDetails);
	protected:
		// ��С
		math::IntSize _size;
		// ����
		sys::TextureAtlas _textureAtlas;
		// y���Ƿ��෴
		bool _reverseY = false;
	};
}