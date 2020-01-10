#pragma once

#include <set>
#include <string>
#include <list>

#include "system.h"


class MazeNode;

class Maze
{
public:
	Maze();
	~Maze();
public:
	// 自动生成	
	bool autoGenerate(int seed, int width, int height);
	// 清空
	void clear();


	const math::Size& getSize();
	std::list<MazeNode*>::const_iterator beginNode();
	std::list<MazeNode*>::const_iterator endNode();
	
	MazeNode* get(int i, int j);
private:
	std::list<MazeNode*> _lstNode;
	MazeNode*** _nodes;
	math::Size _size;
};

//////////////////////////////////////////////////////////////////////////
class MazeNode
{
public:
	math::Vector2 pos;
	// 0，不可行走，1可行走
	int value;
	std::set<MazeNode*> adjacents;
public:
	MazeNode();
	~MazeNode();
public:
	void append(MazeNode* adjacent);
	bool find(MazeNode* adjacent);
	void clear();
};