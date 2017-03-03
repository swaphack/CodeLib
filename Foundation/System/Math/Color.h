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

		Color3B();
		Color3B(uchar r, uchar g, uchar b);
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
		uchar red;
		uchar green;
		uchar blue;
		uchar alpha;

		Color4B();
		Color4B(uchar r, uchar g, uchar b, uchar a);
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

	static void convertColor3BTo3F(const Color3B & b3, Color3F & f3);

	static void convertColor3FTo3B(const Color3F & f3, Color3B & b3);

	static void convertColor4BTo4F(const Color4B & b4, Color4F & f4);

	static void convertColor4FTo4B(const Color4F & f4, Color4B & b4);
}