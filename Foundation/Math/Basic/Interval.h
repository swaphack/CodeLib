#pragma once

#include "EndPoint.h"

namespace math
{
	/**
	*	����
	*/
	struct Interval
	{
	private:
		/**
		*	��Сֵ
		*/
		EndPoint _minEndPoint;
		/**
		*	���ֵ
		*/
		EndPoint _maxEndPoint;
	public:
		Interval();
		/**
		*	�������½�
		*/
		Interval(float minValue, float maxValue);
		/**
		*	���½�����
		*/
		Interval(const EndPoint& minEndPoint, const const EndPoint& maxEndPoint);
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
		EndPointType getMinType();
		/**
		*	�����½�����
		*/
		void setMinType(EndPointType type);
		/**
		*	�Ͻ�����
		*/
		EndPointType getMaxType();
		/**
		*	�����Ͻ�����
		*/
		void setMaxType(EndPointType type);

		/**
		*	�½�ֵ
		*/
		float getMinValue();
		/**
		*	�����½�ֵ
		*/
		void setMinValue(float value);

		/**
		*	�Ͻ�ֵ
		*/
		float getMaxValue();
		/**
		*	�����Ͻ�ֵ
		*/
		void setMaxValue(float value);
	public:
		/**
		*	�Ƿ����
		*/
		bool contains(float value);
	};
}