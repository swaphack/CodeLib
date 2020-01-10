#pragma once

#include "Node.h"

#include "mathlib.h"

namespace alg
{
	/**
	*	µØÍ¼µã
	*/
	struct MapNode : Node
	{
	public:
		/**
		*	×ø±ê
		*/
		math::Vector2 position;
	public:
		MapNode();
		MapNode(const math::Vector2& position);
		virtual ~MapNode();
	public:

	};
}