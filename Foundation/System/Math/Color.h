#pragma once

#include "macros.h"

namespace sys
{
	// color
	struct Color3B
	{
		uchar red;
		uchar green;
		uchar blue;

		Color3B() :red(COLOR_UCHAR_VALUE), green(COLOR_UCHAR_VALUE), blue(COLOR_UCHAR_VALUE){}
		Color3B(uchar r, uchar g, uchar b) :red(r), green(g), blue(b){}

		bool isEquals(const Color3B& color)
		{
			return red == color.red	 && green == color.green && blue == color.blue;
		}

		virtual void operator=(const Color3B& color)
		{
			red = color.red;
			green = color.green;
			blue = color.blue;
		}

		void add(const Color3B& color)
		{
			red += color.red;
			green += color.green;
			blue += color.blue;
		}

		void sub(const Color3B& color)
		{
			red -= color.red;
			green -= color.green;
			blue -= color.blue;
		}

		void mult(const Color3B& color)
		{
			red *= color.red;
			green *= color.green;
			blue *= color.blue;
		}

		void div(const Color3B& color)
		{
			red /= color.red;
			green /= color.green;
			blue /= color.blue;
		}

		void mult(const float ratio)
		{
			red = (uchar)(red * ratio);
			green = (uchar)(red * ratio);
			blue = (uchar)(red * ratio);
		}
	};

	struct Color3F
	{
		float red;
		float green;
		float blue;

		Color3F() :red(1), green(1), blue(1){}
		Color3F(float r, float g, float b) :red(r), green(g), blue(b){}

		bool isEquals(const Color3F& color)
		{
			return red == color.red	 && green == color.green && blue == color.blue;
		}

		virtual void operator=(const Color3F& color)
		{
			red = color.red;
			green = color.green;
			blue = color.blue;
		}

		void add(const Color3F& color)
		{
			red += color.red;
			green += color.green;
			blue += color.blue;
			adjust();
		}

		void sub(const Color3F& color)
		{
			red -= color.red;
			green -= color.green;
			blue -= color.blue;
			adjust();
		}

		void mult(const Color3F& color)
		{
			red *= color.red;
			green *= color.green;
			blue *= color.blue;
			adjust();
		}

		void div(const Color3F& color)
		{
			red /= color.red;
			green /= color.green;
			blue /= color.blue;
			adjust();
		}

		void mult(const float ratio)
		{
			red *= ratio;
			green *= ratio;
			blue *= ratio;
			adjust();
		}
	protected:
		void adjust()
		{
			ADJUST_DURATION_VALUE_RANGE(red, 0, 1, 1);
			ADJUST_DURATION_VALUE_RANGE(green, 0, 1, 1);
			ADJUST_DURATION_VALUE_RANGE(blue, 0, 1, 1);
		}
	};

	struct Color4B
	{
		uchar red;
		uchar green;
		uchar blue;
		uchar alpha;

		Color4B() :red(COLOR_UCHAR_VALUE), green(COLOR_UCHAR_VALUE), blue(COLOR_UCHAR_VALUE), alpha(COLOR_UCHAR_VALUE){}
		Color4B(uchar r, uchar g, uchar b, uchar a) :red(r), green(g), blue(b), alpha(a){}

		bool isEquals(const Color4B& color)
		{
			return red == color.red	 && green == color.green && blue == color.blue && alpha == color.alpha;
		}

		virtual void operator=(const Color4B& color)
		{
			red = color.red;
			green = color.green;
			blue = color.blue;
			alpha = color.alpha;
		}

		void add(const Color4B& color)
		{
			red += color.red;
			green += color.green;
			blue += color.blue;
			alpha += color.alpha;
			adjust();
		}

		void sub(const Color4B& color)
		{
			red -= color.red;
			green -= color.green;
			blue -= color.blue;
			alpha -= color.alpha;
			adjust();
		}

		void mult(const Color4B& color)
		{
			red *= color.red;
			green *= color.green;
			blue *= color.blue;
			alpha *= color.alpha;
			adjust();
		}

		void div(const Color4B& color)
		{
			red /= color.red;
			green /= color.green;
			blue /= color.blue;
			alpha /= color.alpha;
			adjust();
		}

		void mult(const float ratio)
		{
			red = (uchar)(red * ratio);
			green = (uchar)(red * ratio);
			blue = (uchar)(red * ratio);
			alpha = (uchar)(red * ratio);
			adjust();
		}
	protected:
		void adjust()
		{
			ADJUST_DURATION_VALUE_RANGE(red, 0, 255, 255);
			ADJUST_DURATION_VALUE_RANGE(green, 0, 255, 255);
			ADJUST_DURATION_VALUE_RANGE(blue, 0, 255, 255);
			ADJUST_DURATION_VALUE_RANGE(alpha, 0, 255, 255);
		}
	};

	struct Color4F
	{
		float red;
		float green;
		float blue;
		float alpha;

		Color4F() :red(1), green(1), blue(1), alpha(1){}
		Color4F(float r, float g, float b, float a) :red(r), green(g), blue(b), alpha(a){}

		bool isEquals(const Color4F& color)
		{
			return red == color.red	 && green == color.green && blue == color.blue && alpha == color.alpha;
		}

		virtual void operator=(const Color4F& color)
		{
			red = color.red;
			green = color.green;
			blue = color.blue;
			alpha = color.alpha;
		}

		void add(const Color4F& color)
		{
			red += color.red;
			green += color.green;
			blue += color.blue;
			alpha += color.alpha;
			adjust();
		}

		void sub(const Color4F& color)
		{
			red -= color.red;
			green -= color.green;
			blue -= color.blue;
			alpha -= color.alpha;
			adjust();
		}

		void mult(const Color4F& color)
		{
			red *= color.red;
			green *= color.green;
			blue *= color.blue;
			alpha *= color.alpha;
			adjust();
		}

		void div(const Color4F& color)
		{
			red /= color.red;
			green /= color.green;
			blue /= color.blue;
			alpha /= color.alpha;
			adjust();
		}

		void mult(const float ratio)
		{
			red *= ratio;
			green *= ratio;
			blue *= ratio;
			alpha *= ratio;
			adjust();
		}
	protected:
		void adjust()
		{
			ADJUST_DURATION_VALUE_RANGE(red, 0, 1, 1);
			ADJUST_DURATION_VALUE_RANGE(green, 0, 1, 1);
			ADJUST_DURATION_VALUE_RANGE(blue, 0, 1, 1);
			ADJUST_DURATION_VALUE_RANGE(alpha, 0, 1, 1);
		}
	};

	static void convertColor3BTo3F(Color3B & b3, Color3F & f3)
	{
		f3.red = b3.red / COLOR_FLOAT_VALUE;
		f3.green = b3.green / COLOR_FLOAT_VALUE;
		f3.blue = b3.blue / COLOR_FLOAT_VALUE;
	}

	static void convertColor3FTo3B(Color3F & f3, Color3B & b3)
	{
		b3.red = (uchar)(f3.red * COLOR_FLOAT_VALUE);
		b3.green = (uchar)(f3.green * COLOR_FLOAT_VALUE);
		b3.blue = (uchar)(f3.blue * COLOR_FLOAT_VALUE);
	}

	static void convertColor4BTo4F(Color4B & b4, Color4F & f4)
	{
		f4.red = b4.red / COLOR_FLOAT_VALUE;
		f4.green = b4.green / COLOR_FLOAT_VALUE;
		f4.blue = b4.blue / COLOR_FLOAT_VALUE;
		f4.alpha = b4.alpha / COLOR_FLOAT_VALUE;
	}

	static void convertColor4FTo4B(Color4F & f4, Color4B & b4)
	{
		b4.red = (uchar)(f4.red * COLOR_FLOAT_VALUE);
		b4.green = (uchar)(f4.green * COLOR_FLOAT_VALUE);
		b4.blue = (uchar)(f4.blue * COLOR_FLOAT_VALUE);
		b4.alpha = (uchar)(f4.alpha * COLOR_FLOAT_VALUE);
	}
}