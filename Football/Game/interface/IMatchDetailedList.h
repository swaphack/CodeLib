#pragma once

#include "Identity.h"

namespace game
{
	/**
	*	�����嵥
	*/
	class IMatchDetailedList : public Identity
	{
	public:
		virtual ~IMatchDetailedList() {}
	public:
		/**
		*	����ʱ��
		*/
		virtual int getKickOffTime() const = 0;
		/**
		*	��������
		*/
		virtual int getStadiumID() const = 0;
		/**
		*	����
		*/
		virtual int getHostTeamID() const = 0;
		/**
		*	�Ͷ�
		*/
		virtual int getVisitersTeamID() const = 0;
	};
}