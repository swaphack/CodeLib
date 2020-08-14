#version 330 core

#include "Shader/core/vertex/vertex.vs"
#include "Shader/core/vertex/matrix.vs"

uniform Matrix matrix;

void main()
{
	gl_Position = getMVP(matrix) * vec4(v_position, 1.0);
}