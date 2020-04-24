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
		void setImagePath(const std::string& path);
		// 获取图片路径
		const std::string& getImagePath();
	private:
		// 图片结构
		ImageDefine _imageDefine;
	};
}