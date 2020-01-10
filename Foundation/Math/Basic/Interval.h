#pragma once

#include "EndPoint.h"

namespace math
{
	/**
	*	����
	*/
	struct Interval
	{
	public:
		Interval();
		/**
		*	�������½�
		*/
		Interval(float minValue, float maxValue);
		/**
		*	���½�����
		*/
		Interval(const EndPoint& minEndPoint, const EndPoint& maxEndPoint);
	public:
		/**
		*	�½�
		*/
		const EndPoint& getMinEndPoint();
		/**
		*	�����½�
		*/
		void setMinEndPoint(const EndPoint& endPoint);
		/**
		*	�Ͻ�
		*/
		const EndPoint& getMaxEndPoint();
		/**
		*	�����Ͻ�
		*/
		void setMaxEndPoint(const EndPoint& endPoint);
		/**
		*	�½�����
		*/
		EndPointType getMinType() const;
		/**
		*	�����½�����
		*/
		void setMinType(EndPointType type);
		/**
		*	�Ͻ�����
		*/
		EndPointType getMaxType() const;
		/**
		*	�����Ͻ�����
		*/
		void setMaxType(EndPointType type);

		/**
		*	�½�ֵ
		*/
		float getMinValue() const;
		/**
		*	�����½�ֵ
		*/
		void setMinValue(float value);

		/**
		*	�Ͻ�ֵ
		*/
		float getMaxValue() const;
		/**
		*	�����Ͻ�ֵ
		*/
		void setMaxValue(float value);
	public:
		/**
		*	�Ƿ����
		*/
		bool contains(float value);
	private:
		/**
		*	��Сֵ
		*/
		EndPoint _minEndPoint;
		/**
		*	���ֵ
		*/
		EndPoint _maxEndPoint;
	};
}