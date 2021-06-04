#pragma once

namespace math
{
	/**
	*	概率
	*/
	class Probability
	{
	public:
		Probability();
		Probability(float p);
		Probability(float m, float n);
		virtual ~Probability();
	public:
		/**
		*	获取概率值 p
		*/
		float getValue() const;
		/**
		*	获取概率值：1 - p
		*/
		float getInverse() const;
	private:
		/**
		*	概率值
		*/
		float _value = 0;
	};
}