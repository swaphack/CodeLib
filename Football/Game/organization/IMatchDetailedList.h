#pragma once

namespace game
{
	/**
	*	�����嵥
	*/
	class IMatchDetailedList
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
		virtual int getVisiterTeamID() const = 0;
	};
}