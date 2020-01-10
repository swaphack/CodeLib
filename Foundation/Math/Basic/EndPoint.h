#pragma once

namespace math
{
	/**
	*	�߽�����
	*/
	enum EndPointType
	{
		/**
		*	����
		*/
		Include,
		/**
		*	������
		*/
		Exclude,
	};

	/**
	*	�߽�
	*/
	struct EndPoint
	{
	public:
		EndPoint();
		EndPoint(EndPointType type, float value);
		EndPoint(const EndPoint& endPoint);
	public:
		/**
		*	���ñ߽�����
		*/
		void setType(EndPointType type);
		/**
		*	�߽�����
		*/
		EndPointType getType() const;

		/**
		*	���ñ߽�ֵ
		*/
		void setValue(float value);
		/**
		*	�߽�ֵ
		*/
		float getValue() const;
	private:
		/**
		*	�߽�����
		*/
		EndPointType _type = EndPointType::Include;
		/**
		*	�߽�ֵ
		*/
		float _value = 0;
	};
}