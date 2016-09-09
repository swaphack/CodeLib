#pragma once

#include <map>

namespace game
{
	/**
	*	��Ա����
	*/
	class IPlayerMark
	{
	public:
		/**
		*	λ�÷��� {λ�ã�����}
		*/
		typedef std::map<int, int> PositionScore;
	public:
		virtual ~IPlayerMark() {}
	public:
		/**
		*	�����λ�õ�����
		*/
		virtual int getScore() = 0;
		/**
		*	�ض�λ�õ�����
		*/
		virtual int getPositionScore(int nPositionID) = 0;
		/**
		*	����ʽ
		*/
		virtual int getPlayStyle() = 0;
		/**
		*	����ʵ�λ��
		*/
		virtual int getBestFitPosition() const = 0;
		/**
		*	����ʵ�����
		*/
		virtual int getBestFitFormation() const = 0;
		/**
		*	���
		*/
		virtual float getPersonalvalue() const = 0;
	};
}