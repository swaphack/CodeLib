#pragma once

#include "EndPoint.h"

namespace math
{
	/**
	*	区间
	*/
	struct Interval
	{
	public:
		Interval();
		/**
		*	包含上下界
		*/
		Interval(float minValue, float maxValue);
		/**
		*	上下界设置
		*/
		Interval(const EndPoint& minEndPoint, const EndPoint& maxEndPoint);
	public:
		/**
		*	下界
		*/
		const EndPoint& getMinEndPoint();
		/**
		*	设置下界
		*/
		void setMinEndPoint(const EndPoint& endPoint);
		/**
		*	上界
		*/
		const EndPoint& getMaxEndPoint();
		/**
		*	设置上界
		*/
		void setMaxEndPoint(const EndPoint& endPoint);
		/**
		*	下界类型
		*/
		EndPointType getMinType() const;
		/**
		*	设置下界类型
		*/
		void setMinType(EndPointType type);
		/**
		*	上界类型
		*/
		EndPointType getMaxType() const;
		/**
		*	设置上界类型
		*/
		void setMaxType(EndPointType type);

		/**
		*	下界值
		*/
		float getMinValue() const;
		/**
		*	设置下界值
		*/
		void setMinValue(float value);

		/**
		*	上界值
		*/
		float getMaxValue() const;
		/**
		*	设置上界值
		*/
		void setMaxValue(float value);
	public:
		/**
		*	是否包含
		*/
		bool contains(float value);
	private:
		/**
		*	最小值
		*/
		EndPoint _minEndPoint;
		/**
		*	最大值
		*/
		EndPoint _maxEndPoint;
	};
}