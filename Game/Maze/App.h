#pragma once

#include "render.h"

class MazeMap;

class App : public render::RenderApplication
{
public:
	App();
	virtual ~App();
public:
	virtual void show();
private:
	void onKeyBoardListener(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);
private:
	MazeMap* _mazeMap;
};