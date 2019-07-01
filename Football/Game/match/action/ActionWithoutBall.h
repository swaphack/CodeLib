#pragma once

#include "../macros.h"
#include "../Player.h"

namespace game
{
	/**
	*	������
	*/
	class ActionWithoutBall : public Identity, public ITimer
	{
	public:
		ActionWithoutBall();
		virtual ~ActionWithoutBall();
	public:
		/**
		*	������
		*/
		virtual Player* getInitiator();
		/**
		*	������
		*/
		void setInitiator(Player* pPerson);
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
		bool m_bFinish = false;
		Player* m_pPerson = nullptr;
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