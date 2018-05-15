#pragma once

#include <list>
#include <set>

namespace alg
{
	struct AStarNode
	{
	public:
		std::list<AStarNode*> adjacents;
	};

	class AStar
	{
	public:
		virtual void Init();
		void Search();
	protected:
	private:
		std::set<AStarNode*> _nodes;
	};
	
}