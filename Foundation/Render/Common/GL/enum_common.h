#pragma once

// ö��
namespace render
{
	// ά��ģʽ
	enum Dimensions
	{
		ED_NONE,
		ED_2D,
		ED_3D
	};

	// ����״̬
	enum ActionStatus
	{
		EAS_NONE,		// ��״̬
		EAS_RUNNING,	// ����������
		EAS_PAUSE,		// ��ͣ
		EAS_STOP,		// ֹͣ
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
		EMF_MAX,
	};
}