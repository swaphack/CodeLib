#pragma once

#include "CtrlFrame.h"
namespace render
{
	// ͼƬ
	class CtrlImage : public CtrlFrame
	{
	public:
		CtrlImage();
		virtual ~CtrlImage();
	public:
		virtual bool init();
	public:
		/**
		*	����ͼƬ·��
		*/ 
		void setImagePath(const std::string& path);
		/**
		*	����ͼƬ
		*/
		void loadImage(const std::string& path);
		/**
		*	��ȡͼƬ·��
		*/ 
		const std::string& getImagePath();
	private:
		// ͼƬ�ṹ
		sys::ImageDefine _imageDefine;
	};
}