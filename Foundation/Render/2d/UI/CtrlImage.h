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
		void setImagePath(const std::string& path);
		// ��ȡͼƬ·��
		const std::string& getImagePath();
	private:
		// ͼƬ�ṹ
		ImageDefine _imageDefine;
	};
}