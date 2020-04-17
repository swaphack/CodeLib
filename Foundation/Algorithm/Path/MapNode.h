#pragma once

#include "PathNode.h"

#include "mathlib.h"

namespace alg
{
	/**
	*	地图点
	*/
	class MapNode : public PathNode
	{
	public:
		MapNode();
		MapNode(const math::Vector2& position);
		virtual ~MapNode();
	public:
		/**
		*	坐标
		*/
		void setPosition(const math::Vector2& pos);
		/**
		*	坐标
		*/
		const math::Vector2& getPosition() const;
	private:
		/**
		*	坐标
		*/
		math::Vector2 _position;
	};
}