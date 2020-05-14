#pragma once

#include <string>
#include "Light/ColorSample.h"

namespace sys
{
	// ˮƽ���뷽ʽ
	enum class HorizontalAlignment
	{
		LEFT,		// �����
		CENTER,		// ���ж���
		RIGHT,		// �Ҷ���
	};

	// ��ֱ���뷽ʽ
	enum class VerticalAlignment
	{
		TOP,		// ������
		MIDDLE,		// ���ж���
		BOTTOM,		// �׶���
	};

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
		Color3B color;

		// ˮƽ���뷽ʽ
		sys::HorizontalAlignment horizontalAlignment;
		// ��ֱ���뷽ʽ
		sys::VerticalAlignment verticalAlignment;

		TextDefine()
			:filepath("")
			, fontSize(0)
			, horizontalDistance(0)
			, verticalDistance(0)
			, text("")
			, width(0)
			, height(0)
			, horizontalAlignment(sys::HorizontalAlignment::CENTER)
			, verticalAlignment(sys::VerticalAlignment::MIDDLE)
		{

		}
	};
}