#pragma once

#include "Point.h"

namespace game
{
	/**
	*	����
	*/
	struct Rectangle
	{
		Point LeftDown;
		Point RightDown;
		Point RightUp;
		Point LeftUp;
	};
}