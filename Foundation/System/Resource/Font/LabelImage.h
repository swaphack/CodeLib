#pragma once

#include "TextDefine.h"
#include "ILabelLoader.h"
#include "../Image/ImageDetail.h"
namespace sys
{
	class LabelStream;

	// 文本图片
	// 文本变成图片，只关心图片的生成，不考虑实际摆放的位置
	class LabelImage : public ImageDetail, public ILabelLoader
	{
	public:
		LabelImage();
		virtual ~LabelImage();
	public:
		// 加载文本
		virtual bool load(const TextDefine& textDefine);
	private:
		LabelStream* _stream = nullptr;
	};
}