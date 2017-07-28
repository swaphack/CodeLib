#pragma once

#include "macros.h"
#include <map>
#include <vector>

namespace acg
{
	// 顶点类型
	enum class VertexType
	{
		// 无效顶点
		eNone,
		// 开始顶点
		eStart,
		// 结束顶点
		eEnd,
		// 普通顶点
		eRegular,
		// 分裂顶点
		eSplit,
		// 汇合顶点
		eMerge,
	};
	// 顶点信息
	struct VertexInfo
	{
	public:
		// 索引
		int index;
		// 类型
		VertexType type;
		// 点坐标
		sys::Vector2 point;
	public:
		VertexInfo() :index(-1), type(VertexType::eNone)
		{}
	};
	// 边
	struct Edge
	{
	public:
		// 起始点
		sys::Vector2 start;
		// 终止点
		sys::Vector2 end;
	public:
		Edge() {}
		Edge(sys::Vector2 start, sys::Vector2 end) :start(start), end(end){}
	public:
		float distance(const sys::Vector2& point)
		{
			float d0 = sys::Vector2::distance(point, start);
			float d1 = sys::Vector2::distance(point, end);

			return MIN(d0, d1);
		}
		// 点是否在边的左边
		bool onLeftSide(const sys::Vector2& point)
		{
			if (start.y < point.y || end.y > point.y)
			{
				return false;
			}

			if (start.x > point.x && end.x >= point.x)
			{
				return false;
			}

			return sys::Vector2::direction(end - start, point - start) == 1;
		}
		// 点是否是两端点
		bool isVertex(const sys::Vector2& point)
		{
			return start == point || end == point;
		}
	};

	/**
	*	三角形化
	*	自顶向下的扫描方式
	*/
	class Triangulation
	{
	public:
		Triangulation();
		~Triangulation();
	public:
		/**
		*	获取多边形的三角形化顶点
		*	需先对y轴进行排序
		*/
		bool indicesOfPolygon(const sys::Vector2* points, int count);
	protected:
		/**
		*	获取邻边
		*/
		int getNearEdge(const sys::Vector2& point);
		/**
		*	是否有右端顶点
		*/
		bool hasRightVertex(const sys::Vector2& point, const sys::Vector2* points, int count);
		/**
		*	添加辅助边
		*/
		void addAuxiliaryEdge(const sys::Vector2& src, const sys::Vector2& dest);
		/**
		*	移除临时边
		*/
		void removeTemporaryEdge(int index);
		/**
		*	添加临时边
		*/
		void addTemporaryEdge(int index, const Edge& edge);
	private:
		/**
		*	src位于dest之下
		*/
		bool lower(const sys::Vector2& src, const sys::Vector2& dest);
		/**
		*	src位于dest之上
		*/
		bool upper(const sys::Vector2& src, const sys::Vector2& dest);
		/**
		*	判断顶点类型
		*	一条假想的水平扫描线l自上而下地扫过整个平面
		*	先使用Convex.sortByAxisY
		*/
		VertexInfo typeOfVertex(int index, const sys::Vector2* points, int count);
	private:
		// 三角形顶点索引
		int* m_pIndices[3];

		// 辅助边
		std::vector<Edge> m_setAuxiliaryEdges;
	};
}