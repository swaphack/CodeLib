#pragma once

#include "Relation.h"

namespace alg
{
	/**
	*	地图点
	*/
	class MapNode : public Relation
	{
	public:
		MapNode();
		MapNode(const math::Vector2& position);
		MapNode(const math::Vector3& position);
		virtual ~MapNode();
	public:
		/**
		*	坐标
		*/
		void setPosition(const math::Vector2& pos);
		/**
		*	坐标
		*/
		void setPosition(const math::Vector3& pos);
		/**
		*	坐标
		*/
		const math::Vector3& getPosition() const;
	private:
		/**
		*	坐标
		*/
		math::Vector3 _position;
	};
}