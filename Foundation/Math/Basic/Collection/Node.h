#pragma once
#include "Basic/base.h"
#include <string>
#include <cstdint>

namespace math
{
	/**
	*	节点
	*/
	class Node
	{
	public:
		Node();
		virtual ~Node();
	public:
		template<typename T, typename = typename std::enable_if<std::is_base_of<Node, T>::value, T>::type>
		T* as()
		{
			return dynamic_cast<T*>(this);
		}
		template<typename T, typename = typename std::enable_if<std::is_base_of<Node, T>::value, T>::type>
		bool is()
		{
			return dynamic_cast<T*>(this) == nullptr;
		}
	public:
		/**
		*	数据
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(void*, UserData, nullptr);
		/**
		*	标签
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(int32_t, Tag, 0);
		/**
		*	名字
		*/
		CREATE_CLASS_MEMBER(std::string, Name);
	public:
		Node& operator=(const Node& node);
	};
}