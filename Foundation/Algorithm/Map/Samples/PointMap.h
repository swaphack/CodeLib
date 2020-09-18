#pragma once

#include "Map/Base/Map.h"

namespace alg
{
	/**
	*	���־��Ԫ
	*/
	class PointMapCell : public MapCell
	{
	public:
	protected:
	private:
	};

	/**
	*	���־��ͼ 
	*/
	template<typename R,
		typename = std::enable_if<std::is_base_of<MapRelation, R>::value, R>::type>
	class PointMap : public Map<PointMapCell, R>
	{
	public:
		PointMap() {}
		virtual ~PointMap() {}
	public:
		/**
		*	�������ڵ�ľ���
		*/
		virtual float getDistance(uint32_t srcIndex, uint32_t toIndex) const
		{
			auto point0 = getPoint(srcIndex);
			auto point1 = getPoint(toIndex);
			if (point0 == nullptr || point1 == nullptr)
			{
				return -1;
			}

			return math::Vector3::distance(*point0, *point1);
		}
		/**
		*	��������
		*/
		int32_t addPoint(const math::Vector3& point)
		{
			PointMapCell* mp = this->createCell();
			if (mp)
			{
				mp->setPosition(point);
				return mp->getObjectIndex();
			}
			return -1;
		}
		/**
		*	��ȡ������
		*/
		const math::Vector3* getPoint(uint32_t nIndex) const
		{
			auto mp = this->getCell(nIndex);
			if (mp)
			{
				return &mp->getPosition();
			}

			return nullptr;
		}
	};
}
