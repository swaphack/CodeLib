#pragma once


#include "Color.h"
#include "Color3.h"

namespace phy
{
	class Color4B : public Color4<uint8_t>
	{
	public:
		Color4B();
		Color4B(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
		Color4B(const Color3B& color, uint8_t a = 255);
		virtual ~Color4B();
	public:
		CREATE_INDEX_VALUE(Red, 0, uint8_t);
		CREATE_INDEX_VALUE(Green, 1, uint8_t);
		CREATE_INDEX_VALUE(Blue, 2, uint8_t);
		CREATE_INDEX_VALUE(Alpha, 3, uint8_t);
	public:
		Color4B& operator=(const Color4B& value);
	public:
		void adjust();
	};

	class Color4F : public Color4<float>
	{
	public:
		Color4F();
		Color4F(float r, float g, float b, float a);
		Color4F(float r, float g, float b);
		Color4F(const Color3F& color, float a = 1);
		virtual ~Color4F();
	public:
		CREATE_INDEX_VALUE(Red, 0, float);
		CREATE_INDEX_VALUE(Green, 1, float);
		CREATE_INDEX_VALUE(Blue, 2, float);
		CREATE_INDEX_VALUE(Alpha, 3, float);
	public:
		Color4F& operator=(const Color4F& value);
	public:
		void adjust();
	};

	void convertColor4BTo4F(const Color4B& b4, Color4F& f4);

	void convertColor4FTo4B(const Color4F& f4, Color4B& b4);
}