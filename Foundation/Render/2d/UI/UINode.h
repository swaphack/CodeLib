#pragma once

#include "macros.h"

namespace render
{
	class UINode : public Node
	{
	public:
		UINode();
		virtual ~UINode();
	public:
		// ��Ӵ����¼�
		void addTouchHandler(TouchStatus status, RENDER_TOUCH_HANDLER handler);
		// �Ƴ������¼�
		void removeTouchHandler(TouchStatus status);
	private:
	};
}