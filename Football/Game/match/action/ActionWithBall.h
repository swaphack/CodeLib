#pragma once

#include "../macros.h"
#include "../Ball.h"
#include "../Player.h"

namespace game
{
	struct Parabola;
	struct Point;

	/**
	*	������
	*/
	class ActionWithBall : public Identity, public ITimer
	{
	public:
		ActionWithBall();
		virtual ~ActionWithBall();
	public:
		/**
		*	��
		*/
		virtual Ball* getBall();
		/**
		*	��
		*/
		void setBall(Ball* pBall);
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
		bool m_bFinish;
		Ball* m_pBall = nullptr;
		Player* m_pPerson = nullptr;
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