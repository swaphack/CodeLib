#include "DCVertex.h"

using namespace render;


DCVertex::DCVertex()
:Vertex(nullptr)
{

}

DCVertex::~DCVertex()
{

}

void DCVertex::draw()
{
	if (Vertex)
	{
		glVertex3f(Vertex->x, Vertex->y, Vertex->z);
	}
}
