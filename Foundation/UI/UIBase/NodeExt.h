#pragma once

#include "macros.h"
#include "UIProtocol.h"

namespace ui
{
	// ui���ţ�������ʾ���
	class NodeExt :
		public render::Node,
		public UIBoxProtocol
	{
	public:
		NodeExt(render::Node* node);
		virtual ~NodeExt();
	public:
		virtual void draw();
	public:
		// ��ʼ����UI
		virtual void beginDraw();
		// ��������
		virtual void afterDraw();
	private:
		render::Node* _pThis;
	};
}