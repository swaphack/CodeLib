#pragma once

namespace render
{
	// ����״̬
	enum class ActionStatus
	{
		NONE,		// ��״̬
		RUNNING,	// ����������
		PAUSE,		// ��ͣ
		STOP,		// ֹͣ
	};

	// ����ϵͳ��
	class ActionProtocol
	{
	public:
		ActionProtocol();
		virtual ~ActionProtocol();
	public:
		// ��ͣ
		virtual void pause();
		// �ָ�
		virtual void resume();
		// ��ʼ
		virtual void start();
		// ֹͣ
		virtual void stop();
		// �Ƿ����
		bool isFinish();
		// �Ƿ���������
		bool isRunning();
	protected:
		// ����״̬
		ActionStatus _actionStatus;
	};
}