#pragma once

#include "Cell.h"

#include <queue>

namespace idea
{
	// ����
	class Input
	{
	public:
		Input();
		~Input();
	public:
		void push(Cell* msg);
	protected:
	private:
		std::queue<Cell*> _msgs;
	};
}