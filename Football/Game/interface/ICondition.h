#pragma once

namespace game
{
	/**
	*	������
	*/
	class ICondition
	{
	public:
		virtual ~ICondition() {}
	public:
		/**
		*	�Ƿ�ƥ������
		*/
		virtual bool match(float value) const = 0;
	};
}