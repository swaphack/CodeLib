#pragma once

namespace math
{
	/**
	*	链表
	*/
	template<typename T>
	class List
	{
	private:
		struct ListNode 
		{
			/**
			*	节点值
			*/
			CREATE_CLASS_MEMBER(T, Value);
			/**
			*	下一个节点
			*/
			CREATE_CLASS_MEMBER_WITH_DEFAULT(ListNode, Next, nullptr);
		};
	public:
	protected:
	private:
	};
}