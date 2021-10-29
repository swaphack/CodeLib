#pragma once

#include <string>
#include <map>
#include <vector>

#include "Framework/Object.h"

namespace sys
{

	/**
	*	������Ƭ
	*/ 
	class TextureChip : public Object
	{
	public:
		std::string name;
		int width = 0;
		int height = 0;
		int x = 0;
		int y = 0;
		bool rotate = false;
	};
	/**
	*	����
	*/
	class TextureAtlas
	{
	public:
		TextureAtlas();
		virtual ~TextureAtlas();
	public:
		/**
		*	ͼƬ·��
		*/
		void setImagePath(const std::string& imgFilePath);
		/**
		*	ͼƬ·��
		*/
		const std::string& getImagePath() const;
		/**
		*	��������·��
		*/
		void setAtlasPath(const std::string& atlasFilePath);
		/**
		*	��������·��
		*/
		const std::string& getAltasPath() const;
	private:
		// ��������·��
		std::string _atlasFilePath;
		// ͼƬ·��
		std::string _imgFilePath;
	};
}
