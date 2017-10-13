#pragma once

#include "render.h"

class MazeNode;
class Maze;

//////////////////////////////////////////////////////////////////////////
class MazeMap : public render::Node
{
public:
	MazeMap();
	virtual ~MazeMap();
public:
	// ��ص��ã����������޸�ʱ֪ͨ
	virtual bool init();
	
	void flush(Maze* maze);
private:
};

//////////////////////////////////////////////////////////////////////////
class MazeDrawNode : public render::Node
{
public:
	MazeDrawNode();
	virtual ~MazeDrawNode();
public:
	// ��ص��ã����������޸�ʱ֪ͨ
	virtual bool init();

	void setData(MazeNode* data, const sys::Size& cellSize);
private:
	MazeNode* _data;
};