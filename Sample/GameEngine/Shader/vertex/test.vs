#version 330 core

#include "Shader/vertex/matrix.vs"
#include "Shader/vertex/vertex.vs"

uniform Matrix matrix;

out vec2 fragmentUV;
out vec4 fragmentColor;

void main()
{
	vec4 position = vec4(v_position, 1.0);
    gl_Position = get_mvp(matrix) * position;
    fragmentUV = v_texcoord;
    fragmentColor = v_color;	
}