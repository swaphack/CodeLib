#pragma once

#include <cstdint>
#include <vector>
#include <stack>
#include <map>
#include "Path.h"

namespace alg
{
	class MapProtocol;
	/**
	*	A* [1]  （A-Star)算法是一种静态路网中求解最短路径最有效的直接搜索方法，也是许多其他问题的常用启发式算法。
	*	注意——是最有效的直接搜索算法，之后涌现了很多预处理算法（如ALT，CH，HL等等），在线查询效率是A*算法的数千甚至上万倍。
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
	* 
	* 
// A* Search Algorithm
1.  Initialize the open list
2.  Initialize the closed list
	put the starting node on the open list (you can leave its f at zero)

3.  while the open list is not empty
	a) find the node with the least f on the open list, call it "q"

	b) pop q off the open list

	c) generate q's 8 successors and set their
	   parents to q

	d) for each successor
		i) if successor is the goal, stop search

		  successor.g = q.g + distance between successor and q
		  successor.h = distance from goal to successor (This can be done using many ways, we will discuss three heuristics-Manhattan, Diagonal and Euclidean Heuristics)
		  successor.f = successor.g + successor.h

		ii) if a node with the same position as	successor is in the OPEN list which has a
		   lower f than successor, skip this successor

		iii) if a node with the same position as successor  is in the CLOSED list which has
			a lower f than successor, skip this successor 
			
			otherwise, add the node to the open list
	 end (for loop)

	e) push q on the closed list
	end (while loop)
	*/
	class AStar : public Path
	{
		struct AStartNode 
		{
		private:
			// 当前索引
			uint32_t _index = 0;
			// 父节点索引
			int32_t _parent = -1;
			// 距离开始的值
			float _g = 0;
			// 到目标的值
			float _h = 0;
		public:
			AStartNode();
			AStartNode(uint32_t index);
		public:
			// 当前索引
			uint32_t getIndex() const;
			// 父节点索引
			void setParent(int32_t parent);
			int32_t getParent() const;
			// 距离开始的值
			void setG(float value);
			float getG() const;
			// 到目标的值
			void setH(float value);
			float getH() const;

			float getF() const;
		};
	public:
		AStar();
		virtual ~AStar();
	public:
		/**
		*	寻路
		*/
		bool findWay(const MapProtocol* map, uint32_t srcIndex, uint32_t destIndex, std::vector<uint32_t>& path);
	protected:
		/**
		*	初始化节点
		*/
		void initNodes();
		/**
		*	获取节点
		*/
		AStartNode* getAStartNode(uint32_t index);
		/**
		*	获取路径
		*/
		bool getPath(uint32_t srcIndex, uint32_t endIndex, std::vector<uint32_t>& path);
	private:
		// 待检查的节点
		std::set<uint32_t> _openSet;
		// 检查过的节点
		std::set<uint32_t> _closeSet;
		// 节点信息
		std::map<uint32_t, AStartNode> _mapNode;
	};

}