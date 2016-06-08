#pragma once
#include "../AI/ai.h"

namespace idea
{
	class ALU
	{
	public:
		ALU();
		~ALU();
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
		T xor(T a, T b) { return (!a && b)||(!b && a); }

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

		ResultNumber* eval(const char* text) const;
	};

	// ¿€º”∆˜
	class Accumulator
	{
	public:
		Accumulator() { _value = 0; }
		~Accumulator() {}
	public:
		void reset() { _value = 0; }
		void add(double value) { _value += value; }
		double getValue() { return _value; }
	private:
		double _value;
	};

	// ‘ÀÀ„
	class Arithmetical : public IWorker
	{
	public:
		Arithmetical();
		virtual ~Arithmetical();
	public:
		virtual Result* run(Event* e);
		const ALU* getALU();
	protected:
	private:
		ALU _alu;
	};
}