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
		/**
		*	����ͼƬ��Ϣ
		*/
		void loadTextDetails(std::map<std::string, sys::ImageDetail*>& mapDetails);
		/**
		*	�����png
		*/
		bool packImage(const std::string& imgFilePath, const std::string& atlasFilePath);
	private:
		sys::TextDefine _textDefine;
	};
}