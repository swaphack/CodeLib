#pragma once

#include "Common/common.h"

namespace render
{
	enum Dimensions
	{
		ED_NONE,
		ED_2D,
		ED_3D
	};

	class Canvas
	{
	public:
		Canvas();
		virtual ~Canvas();
	public:
		// ����ͼ��
		void draw();
		// ���¶���
		void update(float interval);
		// ����ά��
		void setDimensions(Dimensions d);
		// ��ȡά��
		Dimensions getDimensions();
		// �����Ӵ�
		void setViewPort(float x, float y, float width, float height);
		// ��ȡ����
		Scene* getRoot();
	private:
		// ����
		Scene* _root;
		// ��ͼ
		View* _view;
		// ά��
		Dimensions _dimensions;
		// ��������
		ActionManager* _actionManager;
	};
}