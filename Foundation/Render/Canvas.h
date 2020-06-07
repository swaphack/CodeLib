#pragma once

#include "Common/import.h"
#include "Graphic/import.h"
#include <stack>

namespace render
{
	class Canvas
	{
	public:
		Canvas();
		virtual ~Canvas();
	public:
		static Canvas* getInstance();
	public:
		// ����ͼ��
		void draw();
		// ���¶���
		void update(float interval);
	public:
		// �����Ӵ�
		void setViewPort(float x, float y, float width, float height);
	public:
		// ��ȡ��ͼ
		View* getView();
	public:
		// �Ƿ���ڳ���
		bool hasScene();
		// ѹ�볡��
		void pushScene(Scene* scene);
		// �Ƴ�����
		Scene* popScene();
		// �滻����
		void replaceScene(Scene* scene);
		// �Ƴ����г���
		void removeAllScenes();
		// ��ȡ��ǰ����
		Scene* getCurScene();
	private:
		// ��ͼ
		View* _view;
		// ����
		std::stack<Scene*> _scenes;

		static Canvas* _sCanvas;
	};
}