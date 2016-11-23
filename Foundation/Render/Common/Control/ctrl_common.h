#pragma once

#include "../Node/import.h"

#include "../Touch/import.h"

#include "../Keyboard/import.h"

#include "../macros.h"

namespace render
{
	//---------------------ö��---------------------
	// ������
	enum ModelFace
	{
		EMF_FRONT,		// ǰ��
		EMF_BACK,		// ����
		EMF_LEFT,		// ����
		EMF_RIGHT,		// ����
		EMF_TOP,		// ����
		EMF_BOTTOM,		// ����
	};

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

	//---------------------�ṹ---------------------
	// �ؼ�ͼƬ���������ṹ
	struct Ctrl_ImageDefine : public ImageDefine
	{
		Ctrl_ImageDefine()
		{}
	};

	// �ؼ�ͼƬ���������ṹ
	struct Ctrl_TextDefine : public TextDefine
	{
		// ˮƽ���뷽ʽ
		HorizontalAlignment horizontalAlignment;
		// ��ֱ���뷽ʽ
		VerticalAlignment verticalAlignment;

		Ctrl_TextDefine()
			: horizontalAlignment(EHA_CENTER)
			, verticalAlignment(EVA_CENTER)
		{}
	};
}