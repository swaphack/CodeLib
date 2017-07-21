#pragma once

#include "macros.h"
#include <vector>

namespace sys
{
	/**
	*	三角形化
	*	自顶向下的扫描方式
	*/
	class Triangulation
	{
	public:
		enum class VertexType
		{
			// 开始
			eStart,
			// 结束
			eEnd,
			// 普通
			eRegular,
			// 分裂
			eSplit,
			// 汇合
			eMerge,
		};

		struct Vertex
		{
		public:
			// 索引
			int index;
			// 类型
			VertexType type;

		};
	public:
		Triangulation();
		~Triangulation();
	public:
		/**
		*	顶点数
		*/
		int getIndiceCount();
		/**
		*	顶点索引
		*/
		int* getIndices();
		/**
		*	获取多边形的三角形化顶点
		*	需先对y轴进行排序
		*/
		bool indicesOfPolygon(Vector2* points, int count);
	protected:
		/**
		*	src位于dest之下
		*/
		bool lower(const Vector2& src, const Vector2& dest);
		/**
		*	src位于dest之上
		*/
		bool upper(const Vector2& src, const Vector2& dest);
		/**
		*	判断顶点类型
		*/
		Vertex vertexOfIndex(int index);
	private:
		// 顶点
		Vector2* m_pPoints;
		// 顶点数
		int m_nCount;
		// 顶点索引
		int* m_pIndices;
		// 顶点数
		int m_nIndiceCount;
	};
}