#pragma once

#include "../../Common/common.h"

namespace render
{
	// ����״̬
	enum TouchStatus
	{
		ETS_NONE,	// δ����
		ETS_DOWN,	// ����	
		EST_ON,		// ��ס����
		ETS_UP,		// ����
	};

	typedef bool (Node::*RENDER_TOUCH_HANDLER)(Node*, sys::Point*);
}