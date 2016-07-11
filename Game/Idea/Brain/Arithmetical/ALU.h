#pragma once
#include "../macros.h"

namespace idea
{
	// ËãÊõÂß¼­µ¥Ôª
	class ALU
	{
	public:
		ALU();
		virtual ~ALU();
	public:
		template<typename T>
		T add(T a, T b) { return a + b; }
		template<typename T>
		T sub(T a, T b) { return a - b; }
		template<typename T>
		T mul(T a, T b) { return a * b; }
		template<typename T>
		T div(T a, T b) { return a / b; }

		template<typename T>
		T and(T a, T b) { return a && b; }
		template<typename T>
		T or(T a, T b) { return a || b; }
		template<typename T>
		T not(T a) { return !a; }
		template<typename T>
		T xor(T a, T b) { return (!a && b) || (!b && a); }

		template<typename T>
		T LShift(T a, int bit) { return a << bit; }
		template<typename T>
		T RShift(T a, int bit) { return a >> bit; }

		template<typename T>
		bool isBigger(T a, T b) { return a > b; }
		template<typename T>
		bool isBiggerOrEqual(T a, T b) { return a >= b; }
		template<typename T>
		bool isSmaller(T a, T b) { return a < b; }
		template<typename T>
		bool isSmallerOrEqual(T a, T b) { return a <= b; }
		template<typename T>
		bool isEqual(T a, T b) { return a == b; }

		Result* eval(const char* text) const;
	};
}