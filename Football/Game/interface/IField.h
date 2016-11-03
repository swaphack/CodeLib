#pragma once

namespace game
{
	struct Point;
	struct Line;
	struct Circle;
	struct Rectangle;

	class IFieldSide;

	/**
	*	��������
	*		 left			right
	*	 -- -- -- -- -- -- -- -- -- --
	*   |			   |			  |
	*   |			   |			  |
	*   |			   |			  |
	*   |			   |			  |
	*   |			   |			  |
	*	 -- -- -- -- -- -- -- -- -- --
	*
	*/
	class IField
	{
	public:
		virtual ~IField() {}
	public:
		/**
		*	��ȡ���
		*/
		virtual float getWidth() const = 0;
		/**
		*	��ȡ�߶�
		*/
		virtual float getHeight() const = 0;
		/**
		*	����
		*/
		virtual Line getHalfWayLine() = 0;
		/**
		*	������
		*/
		virtual Circle getKickOffCircle() = 0;
		/**
		*	�ϱ���
		*/
		virtual Line getUpByLine() = 0;
		/**
		*	�±���
		*/
		virtual Line getDownByLine() = 0;

		/**
		*	�����
		*/
		virtual Line getLeftEndLine() = 0;
		/**
		*	�����
		*/
		virtual Rectangle getLeftPenaltyArea() = 0;
		/**
		*	��������
		*/
		virtual Rectangle getLeftGoalArea() = 0;
		/**
		*	��������
		*/
		virtual Line getLeftGoalLine() = 0;
		/**
		*	������
		*/
		virtual Point getLeftPenaltyMark() = 0;
		/**
		*	���Ͻǽ�����
		*/
		virtual Rectangle getLeftUpCornerArea() = 0;
		/**
		*	���½ǽ�����
		*/
		virtual Rectangle getLeftDownCornerArea() = 0;


		/**
		*	�ҵ���
		*/
		virtual Line getRightEndLine() = 0;
		/**
		*	�ҽ���
		*/
		virtual Rectangle getRightPenaltyArea() = 0;
		/**
		*	�ҵ����
		*/
		virtual Point getRightPenaltyMark() = 0;
		/**
		*	���Ͻǽ�����
		*/
		virtual Rectangle getRightUpCornerArea() = 0;
		/**
		*	���½ǽ�����
		*/
		virtual Rectangle getRightDownCornerArea() = 0;
		/**
		*	��������
		*/
		virtual Rectangle getRightGoalArea() = 0;
		/**
		*	��������
		*/
		virtual Line getRightGoalLine() = 0;
	};
}