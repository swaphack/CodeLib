#pragma once

#include "CtrlFrame.h"
namespace render
{
	// 图片
	class CtrlImage : public CtrlFrame
	{
	public:
		CtrlImage();
		virtual ~CtrlImage();
	public:
		virtual bool init();
	public:
		/**
		*	设置图片路径
		*/ 
		void setImagePath(const std::string& path);
		/**
		*	加载图片
		*/
		void loadImage(const std::string& path);
		/**
		*	获取图片路径
		*/ 
		const std::string& getImagePath();
	private:
		// 图片结构
		sys::ImageDefine _imageDefine;
	};
}