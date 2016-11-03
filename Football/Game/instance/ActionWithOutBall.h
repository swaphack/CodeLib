#pragma once

#include "../interface/IAction.h"
#include "../interface/ITimer.h"

namespace game
{
	/**
	*	无球动作
	*/
	class ActionWithOutBall : public IAction, public ITimer
	{
	public:
		ActionWithOutBall();
		virtual ~ActionWithOutBall();
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
	class StartAction : public ActionWithOutBall
	{
	public:
		virtual ~StartAction() {}
	};

	/**
	*	无球跑动动作
	*/
	class RunAction : public ActionWithOutBall
	{
	public:
		virtual ~RunAction() {}
	};

	/**
	*	无球急停动作
	*/
	class EmergencyAction : public ActionWithOutBall
	{
	public:
		virtual ~EmergencyAction() {}
	};

	/**
	*	无球转身动作
	*/
	class TurnAroundAction : public ActionWithOutBall
	{
	public:
		virtual ~TurnAroundAction() {}
	};

	/**
	*	无球假动作
	*/
	class FeintAction : public ActionWithOutBall
	{
	public:
		virtual ~FeintAction() {}
	};
}