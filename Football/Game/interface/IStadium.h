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
		virtual int getID() const = 0;
		/**
		*	比赛场地
		*/
		virtual const IField* getField() const = 0;
		/**
		*	座位数
		*/
		virtual int getSeatCount() const = 0;
		/**
		*	看台数
		*/
		virtual int getStandCount() const = 0;
	};
}