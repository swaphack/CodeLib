#pragma once

#include "../interface/IAction.h"
#include "../interface/ITimer.h"

namespace game
{
	/**
	*	������
	*/
	class ActionWithOutBall : public IAction, public ITimer
	{
	public:
		ActionWithOutBall();
		virtual ~ActionWithOutBall();
	public:
		/**
		*	������
		*/
		virtual IPerson* getInitiator();
		/**
		*	������
		*/
		void setInitiator(IPerson* pPerson);
		/**
		*	ִ�ж���
		*/
		virtual bool run();
		/**
		*	����
		*/
		virtual void update(float dt);
		/**
		*	�Ƿ����
		*/
		virtual bool isFinish();
	private:
		bool m_bFinish;
		IPerson* m_pPerson;
	};

	/**
	*	������������
	*/
	class StartAction : public ActionWithOutBall
	{
	public:
		virtual ~StartAction() {}
	};

	/**
	*	�����ܶ�����
	*/
	class RunAction : public ActionWithOutBall
	{
	public:
		virtual ~RunAction() {}
	};

	/**
	*	����ͣ����
	*/
	class EmergencyAction : public ActionWithOutBall
	{
	public:
		virtual ~EmergencyAction() {}
	};

	/**
	*	����ת����
	*/
	class TurnAroundAction : public ActionWithOutBall
	{
	public:
		virtual ~TurnAroundAction() {}
	};

	/**
	*	����ٶ���
	*/
	class FeintAction : public ActionWithOutBall
	{
	public:
		virtual ~FeintAction() {}
	};
}