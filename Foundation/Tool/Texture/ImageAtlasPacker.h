#pragma once

#include "AtlasPacker.h"

namespace tool
{
	// ͼƬ����������
	class ImageAtlasPacker : public AtlasPacker
	{
	public:
		ImageAtlasPacker();
		virtual ~ImageAtlasPacker();
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
		*	����ͼ����Ϣ
		*/
		void setAtlas(const std::string& imgFilePath, const std::string& atlasFilePath);
	public:
		/**
		*	ͼ��
		*/
		const sys::ImageTextureAtlas& getTextureAtlas() const;
		/**
		*	ͼ��
		*/
		sys::ImageTextureAtlas& getTextureAtlas();
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
		void saveTexAltas(const std::string& imgFilePath, const std::string& atlasFilePath, const std::map<std::string, sys::ImageDetail*>& mapDetails);
		/**
		*	����ͼƬ��Ϣ
		*/
		void loadImageDetails(std::map<std::string, sys::ImageDetail*>& mapDetails, const std::string& format = "*.png");
	public:
		/**
		*	�����png
		*/
		bool packImage(const std::string& imgFilePath, const std::string& atlasFilePath);
	private:
		// ����ͼƬ·��
		std::set<std::string> _images;
		// ͼƬĿ¼
		std::set<std::string> _dirs;

		// ����
		sys::ImageTextureAtlas _textureAtlas;
	};
}