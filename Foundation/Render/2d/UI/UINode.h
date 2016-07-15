#pragma once

#include "macros.h"
#include "UIProtocol.h"

namespace render
{
	// ui�ڵ�
	class UINode : public Node, public UINameProtocol, public UIBoxProtocol
	{
	public:
		UINode();
		virtual ~UINode();
	public:
		// ����
		virtual void draw();
		// �������ƻ�ȡ�ؼ�
		UINameProtocol* getChildByName(const char* name);
	protected:
		// ��ʼ����UI
		virtual void beginDrawUI();
		// ��������
		virtual void afterDrawUI();
	};
}