#pragma once

#include "DrawNode.h"

namespace render
{
	class TestDrawNode : public DrawNode
	{
	public:
		TestDrawNode() 
		{
			_angle = 0;
		}
		virtual ~TestDrawNode(){}
	public:
		void drawSphere()
		{
			//glutSolidSphere(0.5, 20, 20);
		}

		virtual void draw()
		{

			drawSphere();

// 			glClearStencil(0x0);
// 			glClear(GL_STENCIL_BUFFER_BIT);
// 			glStencilFunc(GL_ALWAYS, 1, 0xFF);
// 			glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
// 			glEnable(GL_STENCIL_TEST);
// 
// 			glColor3f(0.5f, 0.5f, 0.5f);
// 			glDepthMask(GL_FALSE);//设置深度缓冲区为只读
// 			glRectf(-1.5f, -1.5f, 1.5f, 1.5f);
// 
// 			glDepthMask(GL_TRUE);//重新启用深度缓冲区
// 
// 			glStencilFunc(GL_EQUAL, 1, 0xFF);
// 			glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
// 			glScalef(1.0f, 1.0f, -1.0f);
// 			drawSphere();
		}
	protected:
	private:
		float _angle;
	};	
}