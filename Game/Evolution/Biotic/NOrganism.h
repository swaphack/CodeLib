#pragma once

#include "macros.h"
#include "NMetabolismProtocol.h"
#include <queue>

namespace nature
{
	// ����
	class NOrganism : public NObject, public NMetabolismProtocol, public NTimer
	{
	protected:
		// �������
		struct TargetHandler
		{
			bool Finish;
			NObject* Target;

			TargetHandler()
				:Finish(false),
				Target(nullptr)
			{}
		};
	public:
		NOrganism();
		virtual ~NOrganism();
	public:
		// ���£�����д
		virtual void update(float dt);
		// ���룬����д
		virtual bool input(NObject* pObject);
		// ע���컯�ص�
		virtual void setOutputHandler(NObject* pTarget, OutputCallback callback);
	protected:
		// �ж��Ƿ�������ͬ������,����д
		virtual bool canAddInputTarget(NObject* pObject);
		// �컯����
		void onOuputHandler(NObject* pObject);
	protected:
		// ͬ����
		std::queue<TargetHandler*> _inputTargets;
		// �컯�ص�����
		std::pair<NObject*, OutputCallback> _outputCallback;
	};
}