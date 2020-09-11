#pragma once

#include <cstdint>
#include <vector>
#include <stack>
#include "Path.h"

namespace alg
{
	class Map;
	/**
	*	A* [1]  （A-Star)算法是一种静态路网中求解最短路径最有效的直接搜索方法，也是许多其他问题的常用启发式算法。注意——是最有效的直接搜索算法，之后涌现了很多预处理算法（如ALT，CH，HL等等），在线查询效率是A*算法的数千甚至上万倍。
	*	公式表示为： f(n)=g(n)+h(n),
	*	其中， f(n) 是从初始状态经由状态n到目标状态的代价估计，
	*	g(n) 是在状态空间中从初始状态到状态n的实际代价，
	*	h(n) 是从状态n到目标状态的最佳路径的估计代价。
	*	（对于路径搜索问题，状态就是图中的节点，代价就是距离）
	*	h(n)的选取
	*	保证找到最短路径（最优解的）条件，关键在于估价函数f(n)的选取（或者说h(n)的选取）。
	*	我们以d(n)表达状态n到目标状态的距离，那么h(n)的选取大致有如下三种情况：
	*	如果h(n)< d(n)到目标状态的实际距离，这种情况下，搜索的点数多，搜索范围大，效率低。但能得到最优解。
	*	如果h(n)=d(n)，即距离估计h(n)等于最短距离，那么搜索将严格沿着最短路径进行， 此时的搜索效率是最高的。
	*	如果 h(n)>d(n)，搜索的点数少，搜索范围小，效率高，但不能保证得到最优解
	*/
	class AStar : public Path
	{
	public:
		AStar();
		virtual ~AStar();
	public:
		/**
		*	寻路
		*/
		bool findWay(const Map* map, uint32_t srcIndex, uint32_t destIndex);
	protected:
		/**
		*	初始化节点
		*/
		void initNodes(const Map* map);
		/**
		*	查找最近节点
		*/
		bool findNeareastNode(const Map* map, uint32_t srcIndex, uint32_t destIndex);
	protected:
		/**
		*	查找当前索引
		*/
		void pushCurrent(const Map* map, uint32_t srcIndex, uint32_t destIndex);
		/**
		*	回滚到上一次
		*/
		void popCurrent(uint32_t srcIndex);
	private:
		// 待检查的节点
		std::set<uint32_t> _waitCheckNode;
		// 检查过的节点
		std::set<uint32_t> _checkedNode;
		// 路线点
		std::stack<uint32_t> _pathNode;
		// 距离
		std::stack<float> _pathDistance;
	};

}