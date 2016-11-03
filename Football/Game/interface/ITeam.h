#pragma once

#include "Identity.h"

#include <map>

namespace game
{
	class IPlayer;
	class ICoach;
	class IFormation;
	class ILineUp;

	/**
	*	��������
	*/
	class ITeam
	{
	public:
		/**
		*	���ͷ��� {���ͣ�����}
		*/
		typedef std::map<int, int> FormationScoreMap;
	public:
		virtual ~ITeam() {}
	public:
		/**
		*	�������ֲ�
		*/
		virtual int getClubID() const = 0;
		/**
		*	��������
		*/
		virtual int getLeagueID() const = 0;
		/**
		*	���͵�����
		*/
		virtual int getFormationScore(int nFormationID) = 0;
		/**
		*	���õ������б�
		*/
		virtual bool getFormationScoreTable(FormationScoreMap& formation) = 0;
		/**
		*	��ȡ������Ϣ
		*/
		virtual const ILineUp* getLineUp() const = 0;
		/**
		*	��ȡ�˶�Ա
		*/ 
		virtual const IPlayer* getPlayer(int nID) const = 0;
		/**
		*	����˶�Ա
		*/
		virtual void addPlayer(IPlayer* pPlayer) = 0;
		/**
		*	�Ƴ��˶�Ա
		*/
		virtual void removePlayer(int nID) const = 0;
		/**
		*	��ȡ����
		*/
		virtual const ICoach* getCoach(int nID) const = 0;
		/**
		*	��ӽ���
		*/
		virtual void addCoach(ICoach* pCoach) = 0;
		/**
		*	�Ƴ�����
		*/
		virtual void removeCoach(int nID) const = 0;
	};
}