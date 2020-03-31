#pragma once

#include "Node.h"
#include "Common/struct/protocol_common.h"

namespace render
{
	class Scheduler;
	// ����
	class Animation : public Node, public ControlProtocol
	{
	public:
		Animation();
		virtual ~Animation();
	public:
		// ��ʼ
		virtual void start();
		// �ָ�
		virtual void pause();
		// ��ͣ
		virtual void resume();
		// ����
		virtual void stop();

		// ��ʱ�����¼�,��Ҫ�޸�
		virtual void updateAnimation(float interval);
	protected:
		// ��Ӷ�ʱ��
		void registerScheduler();
		// �Ƴ���ʱ��
		void unregisterScheduler();
		// ��ʱ�����¼�
		virtual void updateSelf(float interval);
	private:
		// ��ʱ��
		Scheduler* _scheduler;
	};
}