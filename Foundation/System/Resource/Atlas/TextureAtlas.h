#pragma once

#include <string>
#include <map>
#include <vector>

namespace sys
{

	/**
	*	������Ƭ
	*/ 
	struct TextureChip
	{
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
		~TextureAtlas();
	public:
		/**
		*	ͼƬ·��
		*/
		void setImage(const std::string& imgFilePath);
		/**
		*	ͼƬ·��
		*/
		const std::string& getImagePath() const;
		/**
		*	��������·��
		*/
		void setAltasPath(const std::string& altasFilePath);
		/**
		*	��������·��
		*/
		const std::string& getAltasPath() const;
	public:
		/**
		*	���������Ƭ
		*/
		void addChip(const std::string& name, int width, int height, int x, int y, bool rotate = false);
		/**
		*	���������Ƭ
		*/
		void addChip(const TextureChip& chip);
		/**
		*	�Ƴ�������Ƭ
		*/
		void removeChip(const std::string& name);
		/**
		*	����������Ƭ
		*/
		const TextureChip* getChip(const std::string& name) const;
		/**
		*	�Ƴ�����������Ƭ
		*/
		void removeAllChips();
		/**
		*	��ȡ����������Ƭ
		*/
		const std::map<std::string, TextureChip>& getAllChips() const;
	private:
		// ��Ƭ
		std::map<std::string, TextureChip> _chips;
		// ��������·��
		std::string _altasFilePath;
		// ͼƬ·��
		std::string _imgFilePath;
	};
}
