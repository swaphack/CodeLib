#pragma once

#include "Identity.h"

namespace game
{
	class ITeam;
	class IRule;
	class IField;
	class IPartMatch;
	/**
	*	ȫ������
	*/
	class IFullMatch : public Identity
	{
	public:
		virtual ~IFullMatch() {}
	public:
		/**
		*	�ϰ��
		*/
		virtual const IPartMatch* getFirstHalfMatch();
		/**
		*	�°��
		*/
		virtual const IPartMatch* getSecondHalfMatch();
		/**
		*	��ʱ
		*/
		virtual const IPartMatch* getExtraMatch();
		/**
		*	����
		*/
		virtual const ITeam* getHostTeam() const = 0;
		/**
		*	�Ͷ�
		*/
		virtual const ITeam* getVisiterTeam() const = 0;
		/**
		*	��������
		*/
		virtual const IField* getField() const = 0;
		/**
		*	��ȡ����
		*/
		virtual const ITeam* getTeamByID(int nTeamID) const = 0;
		/**
		*	������ʱ��
		*/
		virtual float getFullTime() const = 0;
		/**
		*	�����Ƿ����
		*/
		virtual bool isMatchOver() const = 0;
		/**
		*	ʤ������
		*/
		virtual int getWinTeamID() const = 0;
		/**
		*	ʧ�ܶ���
		*/
		virtual int getLostTeamID() const = 0;
		/**
		*	���ӷ���
		*/
		virtual int getHostScore() const = 0;
		/**
		*	�Ͷӷ���
		*/
		virtual int getVisiterScore() const = 0;
		/**
		*	���ӵ������
		*/
		virtual int getHostPenaltyScore() const = 0;
		/**
		*	�Ͷӵ������
		*/
		virtual int getVisiterPenaltyScore() const = 0;
	};
}