#pragma once

#include "macros.h"
#include "UIProtocol.h"

namespace ui
{
	// ui�ڵ�
	class NodeExt :
		public UINameProtocol,
		public UIBoxProtocol
	{
	public:
		NodeExt(render::Node* node);
		virtual ~NodeExt();
	public:
		virtual void draw();

		// �������ƻ�ȡ�ؼ�
		UINameProtocol* getChildByName(const char* name);
	public:
		// ��ʼ����UI
		virtual void beginDraw();
		// ��������
		virtual void afterDraw();
	private:
		render::Node* _pThis;
	};
}