#pragma once

#include "Node.h"

namespace render
{
	// ����
	class Animation : public Node
	{
	public:
		Animation();
		virtual ~Animation();
	public:
		// ��ʼ
		void start();
		// �ָ�
		void pause();
		// ��ͣ
		void resume();
		// ����
		void stop();

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