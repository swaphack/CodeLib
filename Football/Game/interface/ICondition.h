#pragma once

namespace game
{
	/**
	*	条件型
	*/
	class ICondition
	{
	public:
		virtual ~ICondition() {}
	public:
		/**
		*	是否匹配条件
		*/
		virtual bool match(float value) const = 0;
	};
}