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
	// �Զ�����	
	bool autoGenerate(int seed, int width, int height);
	// ���
	void clear();


	const sys::Size& getSize();
	std::list<MazeNode*>::const_iterator beginNode();
	std::list<MazeNode*>::const_iterator endNode();
	
	MazeNode* get(int i, int j);
private:
	std::list<MazeNode*> _lstNode;
	MazeNode*** _nodes;
	sys::Size _size;
};

//////////////////////////////////////////////////////////////////////////
class MazeNode
{
public:
	sys::Vector2 pos;
	// 0���������ߣ�1������
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