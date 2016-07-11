#pragma once
#include "../macros.h"

#include "ALU.h"
#include "Accumulator.h"

namespace idea
{
	// ����
	class Arithmetical : public IWorker
	{
	public:
		Arithmetical();
		virtual ~Arithmetical();
	public:
		virtual Result* run(Event* e);
	private:
		// �����߼���Ԫ
		ALU* _alu;
	};
}