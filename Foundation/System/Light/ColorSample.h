#pragma once

#include <cstdint>

namespace sys
{

#define COLOR_UCHAR_VALUE (char)255
#define COLOR_FLOAT_VALUE 255.0f

	// color
	struct Color3B
	{
		uint8_t red;
		uint8_t green;
		uint8_t blue;

		Color3B();
		Color3B(uint8_t r, uint8_t g, uint8_t b);
		/**
		*	�Ƿ����
		*/
		bool isEquals(const Color3B& color);
		/**
		*	����=
		*/
		void operator=(const Color3B& color);
		/**
		*	��
		*/
		void add(const Color3B& color);
		/**
		*	��
		*/
		void sub(const Color3B& color);
		/**
		*	����
		*/
		void mult(const Color3B& color);
		/**
		*	����
		*/
		void div(const Color3B& color);
		/**
		*	����
		*/
		void mult(const float ratio);
	};

	struct Color3F
	{
		float red;
		float green;
		float blue;

		Color3F();
		Color3F(float r, float g, float b);
		/**
		*	�Ƿ����
		*/
		bool isEquals(const Color3F& color);
		/**
		*	����=
		*/
		void operator=(const Color3F& color);
		/**
		*	��
		*/
		void add(const Color3F& color);
		/**
		*	��
		*/
		void sub(const Color3F& color);

		/**
		*	����
		*/
		void mult(const Color3F& color);
		/**
		*	����
		*/
		void div(const Color3F& color);
		/**
		*	����
		*/
		void mult(const float ratio);
	protected:
		void adjust();
	};

	struct Color4B
	{
		uint8_t red;
		uint8_t green;
		uint8_t blue;
		uint8_t alpha;

		Color4B();
		Color4B(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
		/**
		*	�Ƿ����
		*/
		bool isEquals(const Color4B& color);
		/**
		*	����=
		*/
		void operator=(const Color4B& color);
		/**
		*	��
		*/
		void add(const Color4B& color);
		/**
		*	��
		*/
		void sub(const Color4B& color);
		/**
		*	����
		*/
		void mult(const Color4B& color);
		/**
		*	����
		*/
		void div(const Color4B& color);
		/**
		*	����
		*/
		void mult(const float ratio);
	protected:
		void adjust();
	};

	struct Color4F
	{
		float red;
		float green;
		float blue;
		float alpha;

		Color4F();
		Color4F(float r, float g, float b, float a);
		/**
		*	�Ƿ����
		*/
		bool isEquals(const Color4F& color);
		/**
		*	����=
		*/
		void operator=(const Color4F& color);
		/**
		*	��
		*/
		void add(const Color4F& color);
		/**
		*	��
		*/
		void sub(const Color4F& color);
		/**
		*	����
		*/
		void mult(const Color4F& color);
		/**
		*	����
		*/
		void div(const Color4F& color);
		/**
		*	����
		*/
		void mult(const float ratio);
	protected:
		void adjust();
	};

	void convertColor3BTo3F(const Color3B & b3, Color3F & f3);

	void convertColor3FTo3B(const Color3F & f3, Color3B & b3);

	void convertColor4BTo4F(const Color4B & b4, Color4F & f4);

	void convertColor4FTo4B(const Color4F & f4, Color4B & b4);
}