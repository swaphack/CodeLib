#version 330 core

#include "Shader/core/vertex/matrix.vs"
#include "Shader/core/vertex/vertex.vs"

uniform Matrix matrix;

uniform float pointScale;


void main()
{
	vec4 pos = vec4(v_position, 1.0);
	gl_Position = getMVP(matrix) * pos;
	
	gl_PointSize = pointScale;
}