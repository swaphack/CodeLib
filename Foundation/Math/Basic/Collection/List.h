#pragma once

namespace math
{
	/**
	*	����
	*/
	template<typename T>
	class List
	{
	private:
		struct ListNode 
		{
			/**
			*	�ڵ�ֵ
			*/
			CREATE_CLASS_MEMBER(T, Value);
			/**
			*	��һ���ڵ�
			*/
			CREATE_CLASS_MEMBER_WITH_DEFAULT(ListNode, Next, nullptr);
		};
	public:
	protected:
	private:
	};
}