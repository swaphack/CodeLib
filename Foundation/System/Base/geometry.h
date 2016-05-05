#pragma once

#include "Types.h"

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

	// 3d
	struct Vector
	{
		float x;
		float y;
		float z;

		Vector():x(0),y(0),z(0){}
		Vector(float x, float y, float z = 0):x(x),y(y),z(z){}
		Vector(const Vector& vector) :x(vector.x), y(vector.y), z(vector.z){}

		void add(const Vector& vector)
		{
			x += vector.x;
			y += vector.y;
			z += vector.z;
		}

		void sub(const Vector& vector)
		{
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;
		}

		void mult(const Vector& vector)
		{
			x *= vector.x;
			y *= vector.y;
			z *= vector.z;
		}

		void div(const Vector& vector)
		{
			x /= vector.x;
			y /= vector.y;
			z /= vector.z;
		}

		void mult(const float ratio)
		{
			x *= ratio;
			y *= ratio;
			z *= ratio;
		}

		bool isZero()
		{
			return x == 0.0f && y == 0.0f && z == 0.0f;
		}

		virtual void operator=(const Vector& vector)
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
		}
	};

	struct Volume
	{
		float width;
		float height;
		float deep;

		Volume():width(0), height(0), deep(0){}
		Volume(float w, float h, float d = 0):width(w), height(h), deep(d){}

	};

	// 2d
	struct Point
	{
		float x;
		float y;

		Point():x(0),y(0){}
		Point(float x, float y):x(x),y(y){}

		void add(const Point& point)
		{
			x += point.x;
			y += point.y;
		}

		void sub(const Point& point)
		{
			x -= point.x;
			y -= point.y;
		}

		void mult(const Point& point)
		{
			x *= point.x;
			y *= point.y;
		}

		void div(const Point& point)
		{
			x /= point.x;
			y /= point.y;
		}

		void mult(const float ratio)
		{
			x *= ratio;
			y *= ratio;
		}
	};

	struct Size
	{
		float width;
		float height;

		Size():width(0), height(0){}
		Size(float w, float h):width(w), height(h){}
	};

	struct Rect
	{
		float x;
		float y;
		float width;
		float height;

		Rect():x(0),y(0),width(0), height(0){}
		Rect(float x, float y, float w, float h):x(x),y(y),width(w), height(h){}
	};

	// color
	struct Color3B 
	{
		uchar red;
		uchar green;
		uchar blue;

		Color3B() :red(COLOR_UCHAR_VALUE), green(COLOR_UCHAR_VALUE), blue(COLOR_UCHAR_VALUE){}
		Color3B(uchar r, uchar g, uchar b):red(r),green(g),blue(b){}

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

		Color3F():red(1),green(1),blue(1){}
		Color3F(float r, float g, float b):red(r),green(g),blue(b){}

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
		Color4B(uchar r, uchar g, uchar b, uchar a):red(r),green(g),blue(b), alpha(a){}

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
		}

		void sub(const Color4B& color)
		{
			red -= color.red;
			green -= color.green;
			blue -= color.blue;
			alpha -= color.alpha;
		}

		void mult(const Color4B& color)
		{
			red *= color.red;
			green *= color.green;
			blue *= color.blue;
			alpha *= color.alpha;
		}

		void div(const Color4B& color)
		{
			red /= color.red;
			green /= color.green;
			blue /= color.blue;
			alpha /= color.alpha;
		}

		void mult(const float ratio)
		{
			red = (uchar)(red * ratio);
			green = (uchar)(red * ratio);
			blue = (uchar)(red * ratio);
			alpha = (uchar)(red * ratio);
		}
	};

	struct Color4F
	{
		float red;
		float green;
		float blue;
		float alpha;

		Color4F():red(1),green(1),blue(1),alpha(1){}
		Color4F(float r, float g, float b, float a):red(r),green(g),blue(b), alpha(a){}

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