#pragma once

namespace idea
{
	// ÀÛ¼ÓÆ÷
	class Accumulator
	{
	public:
		Accumulator() { _value = 0; }
		virtual ~Accumulator() {}
	public:
		void reset() { _value = 0; }
		void add(float value) { _value += value; }
		double getValue() { return _value; }
	private:
		float _value;
	};
}