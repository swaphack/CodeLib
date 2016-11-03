#pragma once

#include "Component.h"

#include "../interface/IPerson.h"
#include "../enum/ePlayerProperty.h"

#include "Body.h"

namespace game
{
	class Person : public Component, public IPerson
	{
	public:
		Person();
		virtual ~Person();
	public:
		/**
		*	��������ֵ
		*/
		template<typename T>
		void setPropertyValue(float value);
		/**
		*	��ȡ����ֵ
		*/
		template<typename T>
		int getPropertyValue() const;
		/**
		*	ִ�ж���
		*/
		virtual bool runAction(IAction* pAction);
	};
}