#pragma once

#include "macros.h"

namespace nature
{
	// 投入化学物质
	class ChemInput
	{
	public:
		ChemInput();
		~ChemInput();
	public:
		// 添加材料
		void addMatrial(NObject* pObject, float amount);
	protected:
	private:
	};
}