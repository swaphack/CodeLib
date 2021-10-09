#pragma once

#include "mathlib.h"
#include <string>
#include <set>
#include <map>

namespace tool
{
	// ����������
	class TexturePacker
	{
	public:
		TexturePacker();
		~TexturePacker();
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
	public:
		/**
		*	���ͼƬ
		*/
		void addImage(const std::string& filepath);
		/**
		*	�Ƴ�ͼƬ
		*/
		void removeImage(const std::string& filepath);
		/**
		*	�Ƴ�����ͼƬ
		*/
		void removeAllImages();
	public:
		/**
		*	���Ŀ¼
		*/
		void addDirectory(const std::string& filepath);
		/**
		*	�Ƴ�ͼƬ
		*/
		void removeDirectory(const std::string& filepath);
		/**
		*	�Ƴ�����ͼƬ
		*/
		void removeAllDirectories();
	public:
		/**
		*	����
		*/
		bool pack(const std::string& filepath);
	public:
		math::IntSize _size;
		// ����ͼƬ·��
		std::set<std::string> _images;
		// ͼƬĿ¼
		std::set<std::string> _dirs;
	};
}