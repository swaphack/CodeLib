#pragma once

#include "system.h"
#include <map>

namespace ai
{
	struct MapCell
	{
	public:
		sys::Object* value;
	public:
		MapCell(sys::Object* value) :value(value)
		{
			if (this->value)
			{
				this->value->retain();
			}
		}

		~MapCell()
		{
			if (this->value)
			{
				this->value->release();
			}
		}
	};
}