#pragma once
#include "../AI/ai.h"

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
	protected:
	private:
	};
}