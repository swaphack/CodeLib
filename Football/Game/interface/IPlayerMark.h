#pragma once

#include <map>

namespace game
{
	/**
	*	球员评分
	*/
	class IPlayerMark
	{
	public:
		/**
		*	位置分数 {位置，分数}
		*/
		typedef std::map<int, int> PositionScore;
	public:
		virtual ~IPlayerMark() {}
	public:
		/**
		*	最合适位置的评分
		*/
		virtual int getScore() = 0;
		/**
		*	特定位置的评分
		*/
		virtual int getPositionScore(int nPositionID) = 0;
		/**
		*	踢球方式
		*/
		virtual int getPlayStyle() = 0;
		/**
		*	最合适的位置
		*/
		virtual int getBestFitPosition() const = 0;
		/**
		*	最合适的阵型
		*/
		virtual int getBestFitFormation() const = 0;
		/**
		*	身价
		*/
		virtual float getPersonalvalue() const = 0;
	};
}