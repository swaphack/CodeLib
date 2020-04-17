#pragma once

#include "PathNode.h"

#include "mathlib.h"

namespace alg
{
	/**
	*	��ͼ��
	*/
	class MapNode : public PathNode
	{
	public:
		MapNode();
		MapNode(const math::Vector2& position);
		virtual ~MapNode();
	public:
		/**
		*	����
		*/
		void setPosition(const math::Vector2& pos);
		/**
		*	����
		*/
		const math::Vector2& getPosition() const;
	private:
		/**
		*	����
		*/
		math::Vector2 _position;
	};
}