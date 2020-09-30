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
		float fontSize = 0;
		// ˮƽ�ּ��
		float horizontalDistance = 0;
		// ��ֱ���
		float verticalDistance = 0;
		// ��ʾ���ı�
		std::string text;

		// ���
		float width = 0;
		// �߶�
		float height = 0;

		// ��ɫ
		Color3B color;

		// �Ӵ�
		bool border = false;

		// ˮƽ���뷽ʽ
		sys::HorizontalAlignment horizontalAlignment = sys::HorizontalAlignment::CENTER;
		// ��ֱ���뷽ʽ
		sys::VerticalAlignment verticalAlignment = sys::VerticalAlignment::MIDDLE;

		TextDefine()
		{

		}
	};
}