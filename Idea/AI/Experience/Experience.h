#pragma once

#include "macros.h"

namespace idea
{
	// ����
	class Experience : public IWorker
	{
	public:
		Experience();
		virtual ~Experience();
	public:
		// �������
		virtual Result* run(Event* e);
	protected:
	private:
	};
}