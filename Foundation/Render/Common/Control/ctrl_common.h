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
		

		Ctrl_TextDefine()
			
		{}
	};
}