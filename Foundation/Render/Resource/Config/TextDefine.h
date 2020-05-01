#pragma once

#include "system.h"
#include <string>

namespace render
{
	// ˮƽ���뷽ʽ
	enum HorizontalAlignment
	{
		EHA_LEFT,		// �����
		EHA_CENTER,		// ���ж���
		EHA_RIGHT,		// �Ҷ���
	};

	// ��ֱ���뷽ʽ
	enum VerticalAlignment
	{
		EVA_TOP,		// ������
		EVA_CENTER,		// ���ж���
		EVA_BOTTOM,		// �׶���
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
		sys::Color3B color;

		// ˮƽ���뷽ʽ
		HorizontalAlignment horizontalAlignment;
		// ��ֱ���뷽ʽ
		VerticalAlignment verticalAlignment;

		TextDefine()
			:filepath("")
			, fontSize(0)
			, horizontalDistance(0)
			, verticalDistance(0)
			, text("")
			, width(0)
			, height(0)
			, horizontalAlignment(EHA_CENTER)
			, verticalAlignment(EVA_CENTER)
		{

		}
	};
}