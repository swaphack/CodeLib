#pragma once

namespace math
{
	/**
	*	边界类型
	*/
	enum EndPointType
	{
		/**
		*	包含
		*/
		Include,
		/**
		*	不包含
		*/
		Exclude,
	};

	/**
	*	边界
	*/
	struct EndPoint
	{
	public:
		EndPoint();
		EndPoint(EndPointType type, float value);
		EndPoint(const EndPoint& endPoint);
	public:
		/**
		*	设置边界类型
		*/
		void setType(EndPointType type);
		/**
		*	边界类型
		*/
		EndPointType getType() const;

		/**
		*	设置边界值
		*/
		void setValue(float value);
		/**
		*	边界值
		*/
		float getValue() const;
	private:
		/**
		*	边界类型
		*/
		EndPointType _type = EndPointType::Include;
		/**
		*	边界值
		*/
		float _value = 0;
	};
}