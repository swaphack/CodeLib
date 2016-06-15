#pragma once

#include "common.h"

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
		// ��������
		inline const ActionManager* getActionManager() { return _actionManager; }
		// ��������
		inline const TouchManager* getTouchManager() { return _touchManager; }
		// ��ȡ�����
		Camera* getCamera();
	private:
		// ����
		Scene* _root;
		// ��ͼ
		View* _view;
		// ά��
		Dimensions _dimensions;
		// ��������
		ActionManager* _actionManager;
		// ��������
		TouchManager* _touchManager;
	};
}