#include "DCVertex.h"

using namespace render;


DCVertex::DCVertex()
{

}

DCVertex::~DCVertex()
{

}

void DCVertex::draw()
{
	glVertex3f(Vertex.x, Vertex.y, Vertex.z);
}
