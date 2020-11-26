#pragma once

#include "Color.h"

namespace phy
{
	class Color3B : public Color3<uint8_t>
	{
	public:
		Color3B();
		Color3B(uint8_t r, uint8_t g, uint8_t b);
		virtual ~Color3B();
	public:
		CREATE_INDEX_VALUE(Red, 0, uint8_t);
		CREATE_INDEX_VALUE(Green, 1, uint8_t);
		CREATE_INDEX_VALUE(Blue, 2, uint8_t);
	public:
		Color3B& operator=(const Color3B& value);
	public:
		void adjust();
	};

	class Color3F : public Color3<float>
	{
	public:
		Color3F();
		Color3F(float r, float g, float b);
		virtual ~Color3F();
	public:
		CREATE_INDEX_VALUE(Red, 0, float);
		CREATE_INDEX_VALUE(Green, 1, float);
		CREATE_INDEX_VALUE(Blue, 2, float);
	public:
		Color3F& operator=(const Color3F& value);
	public:
		void adjust();
	};
	
	void convertColor3BTo3F(const Color3B& b3, Color3F& f3);

	void convertColor3FTo3B(const Color3F& f3, Color3B& b3);
}
