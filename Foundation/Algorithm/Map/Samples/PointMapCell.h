#pragma once

#include "Map/Base/MapCell.h"

namespace alg
{
	/**
	*	��ͼ�������
	*/
	class PointMapCell : public MapCell
	{
	public:
		PointMapCell();
		virtual ~PointMapCell();
	public:
		/**
		*	��������
		*/
		void setPosition(const math::Vector3& pos);
		/**
		*	��ȡ����
		*/
		const math::Vector3& getPosition() const;
	protected:
		math::Vector3 _position;
	};
}