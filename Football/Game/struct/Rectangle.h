#pragma once

#include "Point.h"

namespace game
{
	/**
	*	¾ØÐÎ
	*/
	struct Rectangle
	{
		Point LeftDown;
		Point RightDown;
		Point RightUp;
		Point LeftUp;
	};
}