#pragma once

#include <string>
#include <set>
#include <map>

#include "AtlasPacker.h"

namespace tool
{
	// �ı�����������
	class TextAtlasPacker : public AtlasPacker
	{
	public:
		TextAtlasPacker();
		~TextAtlasPacker();
	public:
		/**
		*	����ͼƬ��Ϣ
		*/
		void setText(const std::string& content, const std::string& fontFilePath, int fontSize);
	public:
		// ����
		const sys::FontTextureAtlas& getTextureAtlas() const;
		/**
		*	����ͼ������
		*/
		void loadTextureAtlas(const std::string& atlasFilePath);
		/**
		*	����ͼ������
		*/
		void saveTextureAtlas(const std::string& atlasFilePath);
	protected:
		/**
		*	�����pngͼƬ����������
		*/
		void saveTexAltas(const std::string& imgFilePath, const std::string& atlasFilePath, const std::map<std::string, sys::FontCharDetail*>& mapDetails);
	public:
		/**
		*	�����png
		*/
		bool packImage(const std::string& imgFilePath, const std::string& atlasFilePath);
	private:
		sys::TextDefine _textDefine;
		// ����
		sys::FontTextureAtlas _textureAtlas;
	};
}