#pragma once

namespace math
{
	/**
	*	����
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
		*	��ȡ����ֵ p
		*/
		float getValue() const;
		/**
		*	��ȡ����ֵ��1 - p
		*/
		float getInverse() const;
	private:
		/**
		*	����ֵ
		*/
		float _value = 0;
	};
}