#pragma once

#include "mathlib.h"

namespace ui
{
	class AutoResizeProtocol
	{
	public:
		virtual ~AutoResizeProtocol() {}
	public:
		/**
		*	������λ�úʹ�С�����ı�ʱ
		*/
		virtual void resize(const math::Size& size) {};
	};
}
