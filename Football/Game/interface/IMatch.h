#pragma once

#include "Identity.h"

namespace game
{
	class ITeam;
	class IRule;
	class IField;
	class IMatchPart;
	/**
	*	����
	*/
	class IMatch : public Identity
	{
	public:
		virtual ~IMatch() {}
	public:
		/**
		*	�ϰ��
		*/
		virtual const IMatchPart* getFirstHalfMatch();
		/**
		*	�°��
		*/
		virtual const IMatchPart* getSecondHalfMatch();
		/**
		*	��ʱ
		*/
		virtual const IMatchPart* getExtraTimeMatch();
		/**
		*	ʤ������
		*/
		virtual int getWinTeamID() const = 0;
		/**
		*	ʧ�ܶ���
		*/
		virtual int getLostTeamID() const = 0;
		/**
		*	��������
		*/
		virtual const IField* getField() const = 0;
		/**
		*	����
		*/
		virtual const ITeam* getHostTeam() const = 0;
		/**
		*	�Ͷ�
		*/
		virtual const ITeam* getVisitersTeam() const = 0;
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
	};
}