#pragma once

#include "Step.h"
#include <vector>

namespace idea
{
	// ����
	class Method : public IWorker
	{
	public:
		Method();
		virtual ~Method();
	public:
		// ��Ӳ���
		void addStep(Step* step);
		// �Ƴ�����
		void removeStep(Step* step);
		// �Ƴ����в���
		void removeAllSteps();
		// ʹ�ò��賢�Խ������
		virtual Result* run(Event* e);
	private:
		// ���輯
		std::vector<Step*> _steps;
	};
}