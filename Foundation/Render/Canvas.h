#pragma once

#include "Common/import.h"
#include "Graphic/import.h"

namespace render
{
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
		void setDimensions(CameraDimensions d);
		// ��ȡά��
		CameraDimensions getDimensions();
		// �����Ӵ�
		void setViewPort(float x, float y, float width, float height);
		// ��ȡ����
		Scene* getRoot();
		// ��ȡ��ͼ
		View* getView();
		// ��������
		inline const ActionManager* getActionManager() { return _actionManager; }
		// ��������
		inline const TouchManager* getTouchManager() { return _touchManager; }
		// ���ƹ���
		inline const DrawCommander* getDrawCommander() { return _drawCommander; }
	private:
		// ����
		Scene* _root;
		// ��ͼ
		View* _view;
		// ά��
		CameraDimensions _dimensions;
		// ��������
		ActionManager* _actionManager;
		// ��������
		TouchManager* _touchManager;
		// ���ƹ���
		DrawCommander* _drawCommander;
	};
}