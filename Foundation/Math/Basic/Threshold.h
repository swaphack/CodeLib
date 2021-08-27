#pragma once

namespace math
{
	/**
	*	阈值
	*/
	template<typename T_Type, typename T_VALUE>
	struct Threshold
	{
	public:
		Threshold()
		{

		}
		Threshold(T_Type type, const T_VALUE& value)
		{
			this->setType(type);
			this->setValue(value);
		}
		Threshold(const Threshold& Threshold)
		{
			this->setType(Threshold->getType());
			this->setValue(Threshold->getValue());
		}
	public:
		/**
		*	设置边界类型
		*/
		void setType(T_Type type)
		{
			_type = type;
		}
		/**
		*	边界类型
		*/
		T_Type getType() const
		{
			return _type;
		}
		/**
		*	设置边界值
		*/
		void setValue(const T_VALUE& value)
		{
			_value = value;
		}
		/**
		*	边界值
		*/
		const T_VALUE& getValue() const
		{
			return _value;
		}
	public:
		bool operator == (const Threshold& threshold)
		{
			return getValue() == threshold.getValue() && getType() == threshold.getType();
		}
		bool operator != (const Threshold& threshold)
		{
			return getValue() != threshold.getValue() || getType() != threshold.getType();
		}
	protected:
		/**
		*	边界类型
		*/
		T_Type _type;
		/**
		*	边界值
		*/
		T_VALUE _value;
	};

	/**
	*	点阈值类型
	*/
	enum class PointThresholdType
	{
		/**
		*	包含
		*/
		Include,
		/**
		*	排除
		*/
		Exclude,
	};

	/**
	*	点阈值
	*/
	template<typename T>
	struct PointThreshold : public Threshold<PointThresholdType, T>
	{
		typedef Threshold<PointThresholdType, T> base;
	public:
		PointThreshold()
		{
			base::setType(PointThresholdType::Include);
			base::setValue(0);
		}
		PointThreshold(PointThresholdType type, const T& value)
		{
			base::setType(type);
			base::setValue(value);
		}
		PointThreshold(const T& value)
		{
			base::setType(PointThresholdType::Include);
			base::setValue(value);
		}
	public:
		/**
		*	获取相反的阈值
		*/
		PointThreshold getNegativeThreshold()
		{
			PointThreshold threshold;
			threshold.setValue(base::getValue());
			threshold.setType((PointThresholdType)(1 - (int)base::getType()));
			return threshold;
		}
	};


	/**
	*	区间阈值类型
	*/
	enum class IntervalThresholdType
	{
		/**
		*	小于
		*/
		Less,
		/**
		*	等于
		*/
		Equal,
		/**
		*	大于
		*/
		Greater,
	};

	/**
	*	区间阈值
	*/
	template<typename T>
	struct IntervalThreshold : public Threshold<IntervalThresholdType, T>
	{
		typedef Threshold<IntervalThresholdType, T> base;
	public:
		IntervalThreshold()
		{
			base::setType(IntervalThresholdType::Equal);
			base::setValue(0);
		}
		IntervalThreshold(IntervalThresholdType type, const T& value)
		{
			base::setType(type);
			base::setValue(value);
		}
		IntervalThreshold(const T& value)
		{
			base::setType(IntervalThresholdType::Equal);
			base::setValue(value);
		}
		IntervalThreshold(const IntervalThreshold& threshold)
		{
			base::setType(threshold.getType());
			base::setValue(threshold.getValue());
		}
	public:
		bool operator < (const IntervalThreshold& value)
		{
			if (base::getValue() > value->getValue()) return false;
			else if (base::getValue() < value->getValue()) return true;

			return static_cast<int>(base::getType()) < static_cast<int>(value->getType());
		}

		bool operator <= (const IntervalThreshold& value)
		{
			if (base::getValue() > value->getValue()) return false;
			else if (base::getValue() < value->getValue()) return true;

			return static_cast<int>(base::getType()) <= static_cast<int>(value->getType());
		}

		bool operator > (const IntervalThreshold& value)
		{
			if (base::getValue() < value->getValue()) return false;
			else if (base::getValue() > value->getValue()) return true;

			return static_cast<int>(base::getType()) > static_cast<int>(value->getType());
		}

		bool operator >= (const IntervalThreshold& value)
		{
			if (base::getValue() < value->getValue()) return false;
			else if (base::getValue() > value->getValue()) return true;

			return static_cast<int>(base::getType()) >= static_cast<int>(value->getType());
		}

		bool operator == (const IntervalThreshold& threshold)
		{
			return base::getValue() == threshold.getValue() && base::getType() == threshold.getType();
		}
		bool operator != (const IntervalThreshold& threshold)
		{
			return base::getValue() != threshold.getValue() || base::getType() != threshold.getType();
		}
	public:
		/**
		*	获取相反的阈值
		*/
		IntervalThreshold getNegativeThreshold(bool minPoint)
		{
			IntervalThreshold threshold;
			threshold.setValue(base::getValue());
			if (minPoint)
			{
				if (base::getType() == IntervalThresholdType::Equal)
				{
					threshold.setType(IntervalThresholdType::Less);
				}
				else if (base::getType() == IntervalThresholdType::Greater)
				{
					threshold.setType(IntervalThresholdType::Equal);
				}
			}
			else
			{
				if (base::getType() == IntervalThresholdType::Equal)
				{
					threshold.setType(IntervalThresholdType::Greater);
				}
				else if (base::getType() == IntervalThresholdType::Less)
				{
					threshold.setType(IntervalThresholdType::Equal);
				}
			}
			return threshold;
		}
	};
}