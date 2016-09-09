#pragma once

#include "IPerson.h"

namespace game
{
	class IScene;
	class IMind;
	/**
	*	扮演角色
	*/
	class IRole : public IPerson
	{
	public:
		virtual ~IRole() {}
	public:
		/**
		*	所属俱乐部
		*/
		virtual int getClubID() const = 0;
		/**
		*	所属队伍
		*/
		virtual int getTeamID() const = 0;
		/**
		*	职位：球员，教练，裁判
		*/
		virtual int getJob() const = 0;
		/**
		*	场上位置
		*/
		virtual int getPosition() const = 0;
		/**
		*	思考的大脑
		*/
		virtual const IMind* getMind() const = 0;
	};
}