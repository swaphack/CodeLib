#pragma once

namespace game
{
	class IBody;
	class IAction;

	/**
	*	��������
	*/
	class IBall
	{
	public:
		virtual ~IBall() {}
	public:
		/**
		*	�뾶
		*/
		virtual float getRadius() const = 0;
		/**
		*	����
		*/
		virtual float getWeight() const = 0;
		/**
		*	���壬���ڶ�������
		*/
		virtual IBody* getBody() = 0;
		/**
		*	ִ�ж���
		*/
		virtual bool runAction(IAction* pAction) = 0;
	};
}