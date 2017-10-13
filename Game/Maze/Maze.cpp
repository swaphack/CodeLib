#include "Maze.h"
#include <ctime>
#include <cstdlib>

#define FULL_ANGEL 360

Maze::Maze()
	:_nodes(nullptr)
{

}

Maze::~Maze()
{
	this->clear();
}

bool Maze::autoGenerate(int seed, int width, int height)
{
	static int MIN_VALUE = 1;
	static int MAX_VALUE = 3;

	sys::Random::getInstance()->setSeed(seed);
	sys::Random::getInstance()->setRange(MIN_VALUE, MAX_VALUE);

	this->clear();

	_size = sys::Size(width, height);
	_nodes = new MazeNode**[height];

	for (int i = 0; i < height; i++)
	{
		_nodes[i] = new MazeNode*[width];

		for (int j = 0; j < width; j++)
		{
			MazeNode* node = new MazeNode();

			node->value = sys::Random::getInstance()->getNextInteger() == MIN_VALUE ? 0 : 1;

			node->pos = sys::Vector2(j, i);

			node->append(this->get(i - 1, j));
			node->append(this->get(i, j - 1));
			//node->append(this->get(i + 1, j));
			//node->append(this->get(i, j + 1));

			_nodes[i][j] = node;
			_lstNode.push_back(node);
		}
	}

	return true;
}

void Maze::clear()
{
	_lstNode.clear();

	delete _nodes;
}

std::list<MazeNode*>::const_iterator Maze::beginNode()
{
	return _lstNode.begin();
}

std::list<MazeNode*>::const_iterator Maze::endNode()
{
	return _lstNode.end();
}

MazeNode* Maze::get(int i, int j)
{
	if (i < 0 || i >= _size.height || j < 0 || j >= _size.width)
	{
		return false;
	}

	return _nodes[i][j];
}

const sys::Size& Maze::getSize()
{
	return _size;
}

//////////////////////////////////////////////////////////////////////////
MazeNode::MazeNode()
	:value(0)
{

}

MazeNode::~MazeNode()
{

}

void MazeNode::append(MazeNode* adjacent)
{
	if (adjacent == nullptr)
	{
		return;
	}	

	if (!this->find(adjacent))
	{
		adjacents.insert(adjacent);
	}

	if (!adjacent->find(this))
	{
		adjacent->append(this);
	}
}

bool MazeNode::find(MazeNode* adjacent)
{
	if (adjacent == nullptr)
	{
		return false;
	}

	return adjacents.find(adjacent) != adjacents.end();
}

void MazeNode::clear()
{
	adjacents.clear();
	value = 0;
	pos = sys::Vector2::Zero;
}
