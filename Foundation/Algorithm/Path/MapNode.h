#pragma once

#include "Node.h"

#include "mathlib.h"

namespace alg
{
	/**
	*	��ͼ��
	*/
	struct MapNode : Node
	{
	public:
		/**
		*	����
		*/
		math::Vector2 position;
	public:
		MapNode();
		MapNode(const math::Vector2& position);
		virtual ~MapNode();
	public:

	};
}