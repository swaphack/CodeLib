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
		*	�����ı���Ϣ
		*/
		void setText(const std::string& content, const std::string& fontFilePath, int fontSize);
		/**
		*	����ͼ����Ϣ
		*/
		void setAtlas(const std::string& imgFilePath, const std::string& atlasFilePath);
	public:
		/**
		*	ͼ��
		*/
		const sys::FontTextureAtlas& getTextureAtlas() const;
		/**
		*	ͼ��
		*/ 
		sys::FontTextureAtlas& getTextureAtlas();
		/**
		*	����ͼ������
		*/
		void loadTextureAtlas(const std::string& imageFilePath, const std::string& atlasFilePath);
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