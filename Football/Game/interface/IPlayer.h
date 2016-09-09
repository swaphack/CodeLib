#pragma once

#include "IRole.h"

namespace game
{
	class IBody;
	class IAction;
	class IPlayerMark;

	/**
	*	�˶�Ա
	*/
	class IPlayer : public IRole
	{
	public:
		virtual ~IPlayer(){}
	public:
		/**
		*	���壬���ڶ�������
		*/
		virtual const IBody* getBody() const = 0;
		/**
		*	��Ա����
		*/
		virtual const IPlayerMark* getMark() const = 0;
		/**
		*	ִ�ж���
		*/
		virtual bool runAction(IAction* pAction);
	};
}