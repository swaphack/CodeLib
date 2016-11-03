#pragma once

#include "../interface/IAction.h"
#include "../interface/ITimer.h"

namespace game
{
	struct Parabola;
	struct Point;

	/**
	*	有球动作
	*/
	class ActionWithBall : public IAction, public ITimer
	{
	public:
		ActionWithBall();
		virtual ~ActionWithBall();
	public:
		/**
		*	球
		*/
		virtual IBall* getBall();
		/**
		*	球
		*/
		void setBall(IBall* pBall);
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
		IBall* m_pBall;
		IPerson* m_pPerson;
	};

	/**
	*	停球
	*/
	class StopBallAction : public ActionWithBall
	{
	public:
		virtual ~StopBallAction() {}
	public:
	};

	/**
	*	传球
	*/
	class PassAction : public ActionWithBall
	{
	public:
		virtual ~PassAction() {}
	public:
		/**
		*	目标点
		*/
		virtual const Point& getDestination();
		/**
		*	传球曲线
		*/
		virtual const Parabola* getParabola() const = 0;
	};	

	/**
	*	运球
	*/
	class DribbleBallAction : public ActionWithBall
	{
	public:
		virtual ~DribbleBallAction() {}
	public:
	};

	/**
	*	拦截球
	*/
	class InterceptBallAction : public ActionWithBall
	{
	public:
		virtual ~InterceptBallAction() {}
	public:
	};

	/**
	*	假动作
	*/
	class FakeBallAction : public ActionWithBall
	{
	public:
		virtual ~FakeBallAction() {}
	public:
	};


	/**
	*	掷界外球
	*/
	class ThrowInBallAction : public ActionWithBall
	{
	public:
		virtual ~ThrowInBallAction() {}
	public:
	};

	/**
	*	射门
	*/
	class ShootBallAction : public ActionWithBall
	{
	public:
		virtual ~ShootBallAction() {}
	public:
	};
}