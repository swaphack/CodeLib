#pragma once

namespace game
{
	class ITeam;
	class IRule;
	class IField;
	class IFieldSide;

	/**
	*	������
	*/
	class IPartMatch
	{
	public:
		virtual ~IPartMatch() {}
	public:
		/**
		*	����ʱ��
		*/
		virtual float getNormalTime() const = 0;
		/**
		*	��ʱʱ��
		*/
		virtual float getAllowanceTime() const = 0;
		/**
		*	�����Ƿ����
		*/
		virtual bool isMatchOver() const = 0;
		/**
		*	��������
		*/
		virtual IField* getField() const = 0;
		/**
		*	��߶���
		*/
		virtual int getLeftTeamID() const = 0;
		/**
		*	�ұ߶���
		*/
		virtual int getRightTeamID() const = 0;
		/**
		*	��߳���
		*/
		virtual IFieldSide* getLeftSide() = 0;
		/**
		*	�ұ߳���
		*/
		virtual IFieldSide* getRightSide() = 0;
		/**
		*	��߷���
		*/
		virtual int getLeftScore() const = 0;
		/**
		*	�ұ߷���
		*/
		virtual int getRightScore() const = 0;
	};
}