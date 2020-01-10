#pragma once
#include "Basic/base.h"
#include <string>
#include <cstdint>

namespace math
{
	/**
	*	�ڵ�
	*/
	class Node
	{
	public:
		Node();
		virtual ~Node();
	public:
		template<typename T, typename = typename std::enable_if<std::is_base_of<Node, T>::value, T>::type>
		T* get()
		{
			return dynamic_cast<T*>(this);
		}
	public:
		/**
		*	����
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(void*, UserData, nullptr);
		/**
		*	��ǩ
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(int32_t, Tag, 0);
		/**
		*	����
		*/
		CREATE_CLASS_MEMBER(std::string, Name);
	};
}