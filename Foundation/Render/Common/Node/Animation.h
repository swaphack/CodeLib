#pragma once

#include "Node.h"

namespace render
{
	// ����
	class Animation : public Node, ControlProtocol
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
		virtual void update(float interval);
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