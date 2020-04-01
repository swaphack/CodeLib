#pragma once

#include "CtrlFrame.h"
#include "2d/ctrl_common.h"

namespace render
{
	class CtrlImage : public CtrlFrame
	{
	public:
		CtrlImage();
		virtual ~CtrlImage();
	public:
		// 设置图片路径
		void setImagePath(const char* path, ImageFormat format = EIF_PNG);
		// 获取图片路径
		const char* getImagePath();
	private:
		// 图片结构
		Ctrl_ImageDefine _imageDefine;
	};
}