#pragma once

namespace game
{
	struct Point;
	struct Line;
	struct Circle;
	struct Rectangle;

	class ITeam;

	/**
	*	�������棨����֮�֣�
	*/
	class IFieldSide
	{
	public:
		virtual ~IFieldSide() {}
	public:
		/**
		*	��������
		*/
		virtual int getTeamID() const = 0;
		/**
		*	����
		*/
		virtual const Line& getEndLine() const = 0;
		/**
		*	������
		*/
		virtual const Line& getGoalLine() const = 0;
		/**
		*	������
		*/
		virtual const Rectangle getGoalArea() const = 0;
		/**
		*	�����
		*/
		virtual const Point& getPenaltyMark() const = 0;
		/**
		*	����
		*/
		virtual const Rectangle& getPenaltyArea() const = 0;
		/**
		*	�������
		*/
		virtual const Rectangle& getLeftCornerArea() const = 0;
		/**
		*	�ҽ�����
		*/
		virtual const Rectangle& getRightCornerArea() const = 0;
		/**
		*	�����
		*/
		virtual Line getLeftByLine() = 0;
		/**
		*	�ұ���
		*/
		virtual Line getRightByLine() = 0;
		/**
		*	����
		*/
		virtual Line getHalfWayLine() = 0;
	};
}