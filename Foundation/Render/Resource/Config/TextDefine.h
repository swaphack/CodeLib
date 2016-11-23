#pragma once

#include "system.h"
#include <string>

namespace render
{
	// �ı����������ṹ
	struct TextDefine
	{
		// �ֿ�·��
		std::string filepath;
		// �����С
		float fontSize;
		// ˮƽ�ּ��
		float horizontalDistance;
		// ��ֱ���
		float verticalDistance;
		// ��ʾ���ı�
		std::string text;

		// ���
		float width;
		// �߶�
		float height;
		// ��ɫ
		sys::Color4B color;

		TextDefine()
			:filepath("")
			, fontSize(0)
			, horizontalDistance(0)
			, verticalDistance(0)
			, text("")
			, width(0)
			, height(0)
		{

		}
	};
}