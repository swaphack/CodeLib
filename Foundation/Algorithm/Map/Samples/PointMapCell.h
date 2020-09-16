#pragma once

#include "Map/Base/MapCell.h"

namespace alg
{
	/**
	*	地图上坐标点
	*/
	class PointMapCell : public MapCell
	{
	public:
		PointMapCell();
		virtual ~PointMapCell();
	public:
		/**
		*	设置坐标
		*/
		void setPosition(const math::Vector3& pos);
		/**
		*	获取坐标
		*/
		const math::Vector3& getPosition() const;
	protected:
		math::Vector3 _position;
	};
}