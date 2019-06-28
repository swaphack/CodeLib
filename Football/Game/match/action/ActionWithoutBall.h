#pragma once

#include "../interface/IAction.h"
#include "../interface/ITimer.h"

namespace game
{
	/**
	*	������
	*/
	class ActionWithoutBall : public IAction, public ITimer
	{
	public:
		ActionWithoutBall();
		virtual ~ActionWithoutBall();
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
	class StartAction : public ActionWithoutBall
	{
	public:
		virtual ~StartAction() {}
	};

	/**
	*	�����ܶ�����
	*/
	class RunAction : public ActionWithoutBall
	{
	public:
		virtual ~RunAction() {}
	};

	/**
	*	����ͣ����
	*/
	class EmergencyAction : public ActionWithoutBall
	{
	public:
		virtual ~EmergencyAction() {}
	};

	/**
	*	����ת����
	*/
	class TurnAroundAction : public ActionWithoutBall
	{
	public:
		virtual ~TurnAroundAction() {}
	};

	/**
	*	����ٶ���
	*/
	class FeintAction : public ActionWithoutBall
	{
	public:
		virtual ~FeintAction() {}
	};
}