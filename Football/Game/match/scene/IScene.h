#pragma once

namespace game
{
	class IField;
	class ITeam;
	class IPlayer;
	class IFullMatch;
	class IPartMatch;

	/**
	*	��������
	*/
	class IScene
	{
	public:
		virtual ~IScene() {}
	public:
		/**
		*	ȫ������
		*/
		virtual const IFullMatch* getFullMatch() const = 0;
		/**
		*	��ǰ������
		*/
		virtual const IPartMatch* getCurrentMatch() const = 0;
		/**
		*	��ǰ������Ա
		*/
		virtual const IPlayer* getCurrentTouchBallPlayer() const = 0;
		/**
		*	�������Ա
		*/
		virtual const IPlayer* getLastTouchBallPlayer() const = 0;
	};
}