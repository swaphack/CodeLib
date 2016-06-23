#pragma once

#include "macros.h"

namespace render
{
	// ui�ڵ�
	class UINode : public Node
	{
	public:
		UINode();
		virtual ~UINode();
	public:
		// ����
		virtual void draw();
		// ���þ��ο��Ƿ�ɼ�
		void setRectVisible(bool status);
		// ��ȡ���ο��Ƿ�ɼ�
		bool isRectVisible();
		// ���þ��ο���ʾ��ɫ
		void setRectColor(const sys::Color4B& color);
		// ��ȡ���ο���ʾ��ɫ
		sys::Color4B getRectColor();
		// ��������
		void setName(const char* name);
		// ��ȡ����
		const char* getName();
		// �������ƻ�ȡ�ؼ�
		UINode* getChildByName(const char* name);
	protected:
		// ��ʼ����UI
		virtual void beginDrawUI();
		//  ����UI
		virtual void onDrawUI();
		// ��������
		virtual void afterDrawUI();
		// ��ʾ��������
		void drawRect();
	private:
		// ���ο���ɫ
		sys::Color4B _rectColor;
		// �Ƿ���ʾ���ο�
		bool _bShowRect;
		// ui�ؼ�����
		std::string _name;
	};
}