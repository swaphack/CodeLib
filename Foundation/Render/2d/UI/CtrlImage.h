#pragma once

#include "CtrlFrame.h"
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
		sys::ImageDefine _imageDefine;
	};
}