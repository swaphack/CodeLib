#pragma once

namespace game
{
	class ISystem;
	/**
	*	ϵͳ������
	*/
	class ISystemController
	{
	public:
		virtual ~ISystemController() {}
	public:
		/**
		*	���һ����ϵͳ
		*/
		virtual void addSystem(ISystem* pSystem) = 0;
		/**
		*	�Ƴ�һ�����е�ϵͳ
		*/
		virtual void removeSystem(ISystem* pSystem) = 0;
		/**
		*	����ʱ�䣬��תϵͳ
		*/
		virtual void update() = 0;
	};
}