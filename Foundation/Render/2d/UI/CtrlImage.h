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
		// ����ͼƬ·��
		void setImagePath(const char* path, ImageFormat format = EIF_PNG);
		// ��ȡͼƬ·��
		const char* getImagePath();
	private:
		// ͼƬ�ṹ
		Ctrl_ImageDefine _imageDefine;
	};
}