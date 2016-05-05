#pragma once

#include "../Node/import.h"

namespace render
{
	//---------------------ö��---------------------

	// �������
	enum FogMode
	{
		EFM_EXP = GL_EXP,
		EFM_EXP2 = GL_EXP2,
		EFM_LINEAR = GL_LINEAR,
	};

	// ���Ч������
	enum FogEffect
	{
		EFE_DONT_CARE = GL_DONT_CARE,
		EFE_NICEST = GL_NICEST,
		EFE_FASTEST = GL_FASTEST,
	};

	// ������
	enum LightIndex
	{
		ELI_NONE,
		ELI_LIGHT0 = GL_LIGHT0,
		ELI_LIGHT1 = GL_LIGHT1,
		ELI_LIGHT2 = GL_LIGHT2,
		ELI_LIGHT3 = GL_LIGHT3,
		ELI_LIGHT4 = GL_LIGHT4,
		ELI_LIGHT5 = GL_LIGHT5,
		ELI_LIGHT6 = GL_LIGHT6,
		ELI_LIGHT7 = GL_LIGHT7,
	};

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
		// ͼƬ��ʽ
		ImageFormat format;

		Ctrl_ImageDefine() 
			:format(EIF_PNG)
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