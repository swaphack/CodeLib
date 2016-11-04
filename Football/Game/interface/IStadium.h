#pragma once

#include "Identity.h"

namespace game
{
	class IField;
	/**
	*	体育馆
	*/
	class IStadium
	{
	public:
		virtual ~IStadium() {}
	public:
		/**
		*	编号
		*/
		virtual int getID() = 0;
		/**
		*	比赛场地
		*/
		virtual const IField* getField() = 0;
		/**
		*	座位数
		*/
		virtual int getSeatCount() = 0;
		/**
		*	看台数
		*/
		virtual int getStandCount() = 0;
	};
}