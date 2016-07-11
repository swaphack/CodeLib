#pragma once

#include "Base/import.h"
#include "Analysis/import.h"
#include "Solution/import.h"
#include "Experience/import.h"
#include "Study/import.h"

namespace idea
{
	// �˹�����
	class AI : public IWorker
	{
	public:
		AI();
		virtual ~AI();
	public:
		virtual Result* run(Event* e);
	protected:
	private:
		// ��������
		Analysis* _analysis;
		// �������
		Solution* _solution;
		// �ܽᾭ��
		Experience* _experience;
		// ѧϰ֪ʶ
		Study* _study;
	};
}