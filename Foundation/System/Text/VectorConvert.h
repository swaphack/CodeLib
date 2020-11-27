#pragma once

#include "mathlib.h"

namespace sys
{
	class VectorConvert
	{
	public:
		static bool convertToVector(const std::string& text, math::Vector2& value);

		static bool convertToVector(const std::string& text, math::Vector3& value);

		static void convertToText(const math::Vector2& value, std::string& text);

		static void convertToText(const math::Vector3& value, std::string& text);
	};
}
