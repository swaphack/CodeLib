#pragma once

#include "Memory.h"

namespace idea
{
	// ϸ����Ԫ
	class Cell
	{
	public:
		Cell();
		virtual ~Cell();
	public:
		Storage* getStorage();
	protected:
	private:
	};
}