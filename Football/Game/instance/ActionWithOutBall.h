#pragma once

#include "../interface/IAction.h"
#include "../interface/ITimer.h"

namespace game
{
	/**
	*	无球动作
	*/
	class ActionWithoutBall : public IAction, public ITimer
	{
	public:
		ActionWithoutBall();
		virtual ~ActionWithoutBall();
	public:
		/**
		*	发起者
		*/
		virtual IPerson* getInitiator();
		/**
		*	发起者
		*/
		void setInitiator(IPerson* pPerson);
		/**
		*	执行动作
		*/
		virtual bool run();
		/**
		*	更新
		*/
		virtual void update(float dt);
		/**
		*	是否结束
		*/
		virtual bool isFinish();
	private:
		bool m_bFinish;
		IPerson* m_pPerson;
	};

	/**
	*	无球启动动作
	*/
	class StartAction : public ActionWithoutBall
	{
	public:
		virtual ~StartAction() {}
	};

	/**
	*	无球跑动动作
	*/
	class RunAction : public ActionWithoutBall
	{
	public:
		virtual ~RunAction() {}
	};

	/**
	*	无球急停动作
	*/
	class EmergencyAction : public ActionWithoutBall
	{
	public:
		virtual ~EmergencyAction() {}
	};

	/**
	*	无球转身动作
	*/
	class TurnAroundAction : public ActionWithoutBall
	{
	public:
		virtual ~TurnAroundAction() {}
	};

	/**
	*	无球假动作
	*/
	class FeintAction : public ActionWithoutBall
	{
	public:
		virtual ~FeintAction() {}
	};
}