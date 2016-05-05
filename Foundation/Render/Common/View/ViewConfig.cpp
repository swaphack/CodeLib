#include "ViewConfig.h"
#include "../GL/import.h"

using namespace render;

ViewConfig::ViewConfig()
{

}

ViewConfig::~ViewConfig()
{

}

void ViewConfig::reset()
{

}

void ViewConfig::apply()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH, GL_NICEST);

	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH, GL_NICEST);

	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH, GL_NICEST);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

// 	glEnable(GL_POINT_SMOOTH);
// 	glHint(GL_POINT_SMOOTH, GL_NICEST);
// 
// 	glEnable(GL_LINE_SMOOTH);
// 	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
// 
// 	glEnable(GL_POLYGON_SMOOTH_HINT);
// 	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
}

void ViewConfig::addSetting(ViewSetting vs, int mark)
{

}
