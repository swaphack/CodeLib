#pragma once

#include <string>
#include <map>
#include <vector>

namespace tool
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
		*	��������ļ�
		*/
		void unpack(const std::string& filepath);
		/**
		*	���������ļ�
		*/
		void pack(const std::string& filepath);
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
	};
}
