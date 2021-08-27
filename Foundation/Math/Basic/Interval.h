#pragma once

#include "Threshold.h"
#include <vector>

namespace math
{
	/**
	*	区间
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
		*	上下界界定
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
		*	包含上下界
		*/
		Interval(const T& minValue, const T& maxValue)
		{
			this->_minThreshold = IntervalThreshold<T>(minValue);
			this->_maxThreshold = IntervalThreshold<T>(maxValue);
		}
		/**
		*	上下界设置
		*/
		Interval(const IntervalThreshold<T>& minThreshold, const IntervalThreshold<T>& maxThreshold)
		{
			this->_minThreshold = minThreshold;
			this->_maxThreshold = maxThreshold;
		}
	public:
		/**
		*	下界
		*/
		const IntervalThreshold<T>& getMinThreshold() const
		{
			return this->_minThreshold;
		}
		/**
		*	下界
		*/
		IntervalThreshold<T>& getMinThreshold()
		{
			return this->_minThreshold;
		}
		/**
		*	设置下界
		*/
		void setMinThreshold(const IntervalThreshold<T>& threshold)
		{
			this->_minThreshold = threshold;
		}
		/**
		*	上界
		*/
		const IntervalThreshold<T>& getMaxThreshold() const
		{
			return _maxThreshold;
		}
		/**
		*	上界
		*/
		IntervalThreshold<T>& getMaxThreshold()
		{
			return _maxThreshold;
		}
		/**
		*	设置上界
		*/
		void setMaxThreshold(const IntervalThreshold<T>& threshold)
		{
			_maxThreshold = threshold;
		}
		/**
		*	下界类型
		*/
		IntervalThresholdType getMinType() const
		{
			return _minThreshold.getType();
		}
		/**
		*	设置下界类型
		*/
		void setMinType(IntervalThresholdType type)
		{
			return _minThreshold.setType(type);
		}
		/**
		*	上界类型
		*/
		IntervalThresholdType getMaxType() const
		{
			return _maxThreshold.getType();
		}
		/**
		*	设置上界类型
		*/
		void setMaxType(IntervalThresholdType type)
		{
			return _maxThreshold.setType(type);
		}

		/**
		*	下界值
		*/
		const T& getMinValue() const
		{
			return _minThreshold.getValue();
		}
		/**
		*	设置下界值
		*/
		void setMinValue(const T& value)
		{
			return _minThreshold.setValue(value);
		}

		/**
		*	上界值
		*/
		const T& getMaxValue() const
		{
			return _maxThreshold.getValue();
		}
		/**
		*	设置上界值
		*/
		void setMaxValue(const T& value)
		{
			return _maxThreshold.setValue(value);
		}
	public:
		/**
		*	是否包含
		*/
		bool contains(const T& value) const
		{
			if (value < this->getMinValue() || value > this->getMaxValue())
			{
				return false;
			}

			// 大于等于
			if (this->getMinType() != IntervalThresholdType::Equal)
			{
				if (value == this->getMinValue())
				{
					return false;
				}
			}
			// 小于等于
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
		*	是否相交
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
		*	并集 C|A
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
		*	交集 C&A
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
		*	补集 C/A = C - C&A
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
		*	是否有效
		*/
		bool isValid() const
		{
			return (this->getMinType() != IntervalThresholdType::Less)
				&& (this->getMaxType() != IntervalThresholdType::Greater);
		}
		/**
		*	是否为空
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
		*	最小值
		*/
		IntervalThreshold<T> _minThreshold;
		/**
		*	最大值
		*/
		IntervalThreshold<T> _maxThreshold;
	};
}