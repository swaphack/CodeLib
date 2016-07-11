#pragma once
#include "../macros.h"

#include "ALU.h"
#include "Accumulator.h"

namespace idea
{
	// 运算
	class Arithmetical : public IWorker
	{
	public:
		Arithmetical();
		virtual ~Arithmetical();
	public:
		virtual Result* run(Event* e);
	private:
		// 算术逻辑单元
		ALU* _alu;
	};
}