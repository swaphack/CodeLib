#pragma once

#include "physicslib.h"

namespace sys
{
	class ColorConvert
	{
	public:
		static bool convertToColor(const std::string& text, phy::Color3B& color);

		static bool convertToColor(const std::string& text, phy::Color4B& color);

		static bool convertToColor(const std::string& text, phy::Color3F& color);

		static bool convertToColor(const std::string& text, phy::Color4F& color);

		static void convertToText(const phy::Color3B& color, std::string& text);

		static void convertToText(const phy::Color4B& color, std::string& text);

		static void convertToText(const phy::Color3F& color, std::string& text);

		static void convertToText(const phy::Color4F& color, std::string& text);
	};
}
