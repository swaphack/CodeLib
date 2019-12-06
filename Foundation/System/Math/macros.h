#pragma once

#include "Base/import.h"

namespace sys
{
	// �޷���8λ
	static const uint8 COLOR_UCHAR_VALUE = 255;
	// ������8λ
	static const float COLOR_FLOAT_VALUE = 255.0f;

	// ��������ֵ������
#define ADJUST_DURATION_VALUE_RANGE(r, min, max, delta) { while (r < min) r += delta; while (r > max) r -= delta; }
	// �����޶�ֵ������
#define ADJUST_LIMIT_VALUE_RANGE(r, min, max) { if (r < min) r = min; if (r > max) r = max; }


}