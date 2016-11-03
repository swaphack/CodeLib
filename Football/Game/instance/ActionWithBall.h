#pragma once

#include "../interface/IAction.h"
#include "../interface/ITimer.h"

namespace game
{
	struct Parabola;
	struct Point;

	/**
	*	������
	*/
	class ActionWithBall : public IAction, public ITimer
	{
	public:
		ActionWithBall();
		virtual ~ActionWithBall();
	public:
		/**
		*	��
		*/
		virtual IBall* getBall();
		/**
		*	��
		*/
		void setBall(IBall* pBall);
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
		IBall* m_pBall;
		IPerson* m_pPerson;
	};

	/**
	*	ͣ��
	*/
	class StopBallAction : public ActionWithBall
	{
	public:
		virtual ~StopBallAction() {}
	public:
	};

	/**
	*	����
	*/
	class PassAction : public ActionWithBall
	{
	public:
		virtual ~PassAction() {}
	public:
		/**
		*	Ŀ���
		*/
		virtual const Point& getDestination();
		/**
		*	��������
		*/
		virtual const Parabola* getParabola() const = 0;
	};	

	/**
	*	����
	*/
	class DribbleBallAction : public ActionWithBall
	{
	public:
		virtual ~DribbleBallAction() {}
	public:
	};

	/**
	*	������
	*/
	class InterceptBallAction : public ActionWithBall
	{
	public:
		virtual ~InterceptBallAction() {}
	public:
	};

	/**
	*	�ٶ���
	*/
	class FakeBallAction : public ActionWithBall
	{
	public:
		virtual ~FakeBallAction() {}
	public:
	};


	/**
	*	��������
	*/
	class ThrowInBallAction : public ActionWithBall
	{
	public:
		virtual ~ThrowInBallAction() {}
	public:
	};

	/**
	*	����
	*/
	class ShootBallAction : public ActionWithBall
	{
	public:
		virtual ~ShootBallAction() {}
	public:
	};
}