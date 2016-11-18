#pragma once

#include "../Base/import.h"

namespace sys
{
	// 无符号8位
	static const uchar COLOR_UCHAR_VALUE = 255;
	// 单精度8位
	static const float COLOR_FLOAT_VALUE = 255.0f;

	// 调整周期值的区间
#define ADJUST_DURATION_VALUE_RANGE(r, min, max, delta) { while (r < min) r += delta; while (r > max) r -= delta; }
	// 调整限定值得区间
#define ADJUST_LIMIT_VALUE_RANGE(r, min, max) { if (r < min) r = min; if (r > max) r = max; }

#ifndef PI
#define PI 3.14159265358979323846f
#endif
}