#include "Graph.h"

using namespace math;

Graph::Graph()
{

}

Graph::~Graph()
{

}

void Graph::createLink(GraphNode* src, GraphNode* dest)
{
	if (src == nullptr || dest == nullptr)
	{
		return;
	}

	if (!isCycle())
	{// 允许环
		if (src == dest)
		{
			return;
		}
	}

	if (isDirected())
	{
		src->addLink(dest);
	}
	else
	{
		src->addLink(dest);
		dest->addLink(src);
	}
}

void Graph::breakLink(GraphNode* src, GraphNode* dest)
{
	if (src == nullptr || dest == nullptr)
	{
		return;
	}

	if (!isCycle())
	{// 允许环
		if (src == dest)
		{
			return;
		}
	}

	if (isDirected())
	{
		src->removeLinkWithCleanup(dest, false);
	}
	else
	{
		src->removeLinkWithCleanup(dest, false);
		dest->removeLinkWithCleanup(src, false);
	}
}

bool Graph::isDirected()
{
	return false;
}

bool Graph::isCycle()
{
	return false;
}

bool Graph::isMultipleEdges()
{
	return false;
}

//////////////////////////////////////////////////////////////////////////
bool SimpleGraph::isDirected()
{
	return false;
}

bool SimpleGraph::isCycle()
{
	return false;
}


//////////////////////////////////////////////////////////////////////////
bool DirectedGraph::isDirected()
{
	return false;
}

bool DirectedGraph::isCycle()
{
	return true;
}

