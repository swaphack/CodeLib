#pragma once

namespace game
{
	struct Point;
	struct Line;
	struct Circle;
	struct Rectangle;

	class ITeam;

	/**
	*	������ֻ�������ڳ���
	*/
	class IFieldSide
	{
	public:
		virtual ~IFieldSide() {}
	public:
		/**
		*	��������
		*/
		virtual const ITeam* getTeam() const = 0;
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
		virtual const Line& getLeftByLine() const = 0;
		/**
		*	�ұ���
		*/
		virtual const Line& getRightByLine() const = 0;
		/**
		*	����
		*/
		virtual const Line& getHalfWayLine() const = 0;
	};
}