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
		*	设置属性值
		*/
		template<typename T>
		void setPropertyValue(float value);
		/**
		*	获取属性值
		*/
		template<typename T>
		int getPropertyValue() const;
		/**
		*	执行动作
		*/
		virtual bool runAction(IAction* pAction);
	};
}