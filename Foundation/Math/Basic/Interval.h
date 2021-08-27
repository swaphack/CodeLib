#pragma once

#include "Threshold.h"
#include <vector>

namespace math
{
	/**
	*	����
	*/
	template<typename T>
	struct Interval
	{
	public:
		Interval()
		{
			this->_minThreshold = IntervalThreshold<T>(IntervalThresholdType::Greater, 0);
			this->_maxThreshold = IntervalThreshold<T>(IntervalThresholdType::Less, 0);
		}
		/**
		*	���½�綨
		*/
		Interval(const PointThreshold<T>& minValue, const PointThreshold<T>& maxValue)
		{
			IntervalThresholdType eMinType = IntervalThresholdType::Equal;
			IntervalThresholdType eMaxType = IntervalThresholdType::Equal;

			if (minValue->getType() == PointThresholdType::Exclude)
			{
				eMinType = IntervalThresholdType::Greater;
			}
			if (maxValue->getType() == PointThresholdType::Exclude)
			{
				eMaxType = IntervalThresholdType::Less;
			}

			this->_minThreshold = IntervalThreshold<T>(eMinType, minValue->getValue());
			this->_maxThreshold = IntervalThreshold<T>(eMaxType, maxValue->getValue());
		}
		/**
		*	�������½�
		*/
		Interval(const T& minValue, const T& maxValue)
		{
			this->_minThreshold = IntervalThreshold<T>(minValue);
			this->_maxThreshold = IntervalThreshold<T>(maxValue);
		}
		/**
		*	���½�����
		*/
		Interval(const IntervalThreshold<T>& minThreshold, const IntervalThreshold<T>& maxThreshold)
		{
			this->_minThreshold = minThreshold;
			this->_maxThreshold = maxThreshold;
		}
	public:
		/**
		*	�½�
		*/
		const IntervalThreshold<T>& getMinThreshold() const
		{
			return this->_minThreshold;
		}
		/**
		*	�½�
		*/
		IntervalThreshold<T>& getMinThreshold()
		{
			return this->_minThreshold;
		}
		/**
		*	�����½�
		*/
		void setMinThreshold(const IntervalThreshold<T>& threshold)
		{
			this->_minThreshold = threshold;
		}
		/**
		*	�Ͻ�
		*/
		const IntervalThreshold<T>& getMaxThreshold() const
		{
			return _maxThreshold;
		}
		/**
		*	�Ͻ�
		*/
		IntervalThreshold<T>& getMaxThreshold()
		{
			return _maxThreshold;
		}
		/**
		*	�����Ͻ�
		*/
		void setMaxThreshold(const IntervalThreshold<T>& threshold)
		{
			_maxThreshold = threshold;
		}
		/**
		*	�½�����
		*/
		IntervalThresholdType getMinType() const
		{
			return _minThreshold.getType();
		}
		/**
		*	�����½�����
		*/
		void setMinType(IntervalThresholdType type)
		{
			return _minThreshold.setType(type);
		}
		/**
		*	�Ͻ�����
		*/
		IntervalThresholdType getMaxType() const
		{
			return _maxThreshold.getType();
		}
		/**
		*	�����Ͻ�����
		*/
		void setMaxType(IntervalThresholdType type)
		{
			return _maxThreshold.setType(type);
		}

		/**
		*	�½�ֵ
		*/
		const T& getMinValue() const
		{
			return _minThreshold.getValue();
		}
		/**
		*	�����½�ֵ
		*/
		void setMinValue(const T& value)
		{
			return _minThreshold.setValue(value);
		}

		/**
		*	�Ͻ�ֵ
		*/
		const T& getMaxValue() const
		{
			return _maxThreshold.getValue();
		}
		/**
		*	�����Ͻ�ֵ
		*/
		void setMaxValue(const T& value)
		{
			return _maxThreshold.setValue(value);
		}
	public:
		/**
		*	�Ƿ����
		*/
		bool contains(const T& value) const
		{
			if (value < this->getMinValue() || value > this->getMaxValue())
			{
				return false;
			}

			// ���ڵ���
			if (this->getMinType() != IntervalThresholdType::Equal)
			{
				if (value == this->getMinValue())
				{
					return false;
				}
			}
			// С�ڵ���
			if (this->getMaxType() != IntervalThresholdType::Equal)
			{
				if (value == this->getMaxValue())
				{
					return false;
				}
			}

			return true;
		}
		/**
		*	�Ƿ��ཻ
		*/
		bool intersects(const Interval& target) const
		{
			bool bContainsMin = target->getMinThreshold() >= this->getMinThreshold()
				&& target->getMinThreshold() <= this->getMaxThreshold();

			bool bContainsMax = target->getMaxThreshold() >= this->getMinThreshold()
				&& target->getMaxThreshold() <= this->getMaxThreshold();

			return bContainsMin || bContainsMax;
		}

		/**
		*	���� C|A
		*/
		Interval getUnionInterval(const Interval& target) const
		{
			Interval value;
			if (!intersects(target))
			{
				return value;
			}

			IntervalThreshold<T> min = MIN(this->getMinThreshold(), target->getMinThreshold());
			IntervalThreshold<T> max = MAX(this->getMaxThreshold(), target->getMaxThreshold());

			value.setMinThreshold(min);
			value.setMaxThreshold(max);

			return value;
		}

		/**
		*	���� C&A
		*/
		Interval getIntersectInterval(const Interval& target) const
		{
			Interval value;
			if (!intersects(target))
			{
				return value;
			}

			IntervalThreshold<T> min = MAX(this->getMinThreshold(), target->getMinThreshold());
			IntervalThreshold<T> max = MIN(this->getMaxThreshold(), target->getMaxThreshold());

			value.setMinThreshold(min);
			value.setMaxThreshold(max);

			return value;
		}

		/**
		*	���� C/A = C - C&A
		*/
		std::vector<Interval> getComplementaryInterval(const Interval& target) const
		{
			std::vector<Interval> values;

			Interval intersection = getIntersectInterval(target);
			if (!intersection.isVaild())
			{
				values.push_back(*this);
				return values;
			}


			Interval leftInterval;
			leftInterval.setMinThreshold(this->getMinThreshold());

			Interval rightInterval;
			rightInterval.setMaxThreshold(this->getMaxThreshold());

			if (intersection.getMinThreshold() > this->getMinThreshold())
			{
				leftInterval.setMinThreshold(this->getMinThreshold());
				leftInterval.setMaxThreshold(intersection.getMinThreshold().getNegativeThreshold(true));
			}

			if (intersection.getMaxThreshold() < this->getMaxThreshold())
			{
				rightInterval.setMinThreshold(intersection.getMaxThreshold().getNegativeThreshold(false));
				rightInterval.setMaxThreshold(this->getMaxThreshold());
			}

			if (leftInterval.isValid() && !leftInterval.isEmpty())
			{
				values.push_back(leftInterval);
			}

			if (rightInterval.isValid() && !rightInterval.isEmpty())
			{
				values.push_back(rightInterval);
			}

			return values;
		}
	public:
		/**
		*	�Ƿ���Ч
		*/
		bool isValid() const
		{
			return (this->getMinType() != IntervalThresholdType::Less)
				&& (this->getMaxType() != IntervalThresholdType::Greater);
		}
		/**
		*	�Ƿ�Ϊ��
		*/
		bool isEmpty() const
		{
			if (this->getMinValue() > this->getMaxValue()) return true;
			if (this->getMinValue() < this->getMaxValue()) return false;
			if ((int)this->getMinType() > (int)this->getMaxType()) return false;

			return true;
		}
	private:
		/**
		*	��Сֵ
		*/
		IntervalThreshold<T> _minThreshold;
		/**
		*	���ֵ
		*/
		IntervalThreshold<T> _maxThreshold;
	};
}