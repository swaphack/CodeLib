#pragma once

namespace game
{
	class IField;
	class ITeam;
	class IPlayer;
	class IFullMatch;
	class IPartMatch;

	/**
	*	比赛场景
	*/
	class IScene
	{
	public:
		virtual ~IScene() {}
	public:
		/**
		*	全场比赛
		*/
		virtual const IFullMatch* getFullMatch() const = 0;
		/**
		*	当前比赛段
		*/
		virtual const IPartMatch* getCurrentMatch() const = 0;
		/**
		*	当前触球球员
		*/
		virtual const IPlayer* getCurrentTouchBallPlayer() const = 0;
		/**
		*	最后触球球员
		*/
		virtual const IPlayer* getLastTouchBallPlayer() const = 0;
	};
}