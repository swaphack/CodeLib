#pragma once

#include "macros.h"
#include <vector>

namespace acg
{
	/**
	*	顶点
	*/
	class VertexSet
	{
	public:
		VertexSet();
		~VertexSet();
	public:
		// 顶点数量
		int count();
		// 添加一个顶点
		void add(const sys::Vector2& point);
		// 移除一个顶点
		void remove(const sys::Vector2& point);
		// 移除一个顶点
		void remove(int index);
		// 清空所有顶点
		void clear();
		// 转化为数组
		sys::Vector2* toArray();
		// 第一个顶点
		sys::Vector2* head();
		// 最后一个顶点
		sys::Vector2* tail();
		// 尾部追加一个顶点集合
		void append(const VertexSet& second);
		// 索引顶点
		sys::Vector2& operator[](int index);
	private:
		std::vector<sys::Vector2> m_vecPoint;
	};
}