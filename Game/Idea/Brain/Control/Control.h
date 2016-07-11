#pragma once

#include "../macros.h"
#include "../Arithmetical/import.h"
#include "../Memory/import.h"

namespace idea
{
	// ����
	class Control : public IWorker
	{
	public:
		Control();
		virtual ~Control();
	public:
		// �����߼����㵥Ԫ
		void setArithmetical(Arithmetical* arithmetical);
		// �����ڴ����Ԫ
		void setMemory(Memory* memory);
		// �����¼�
		virtual Result* run(Event* e);
	protected:
		Arithmetical* getArithmetical();
		Memory* getMemory();
	private:
		// �߼����㵥Ԫ
		Arithmetical* _arithmetical;
		// �ڴ����Ԫ
		Memory* _memory;
		// aiģ��
		AI* _ai;
	};
}