#version 330 core

#include "Shader/vertex/matrix.vs"
#include "Shader/vertex/vertex.vs"

uniform Matrix matrix;


out vec3 fragmentPosition;

void main()
{
	vec4 position = vec4(v_position, 1.0);
    vec4 pos = get_mvp(matrix) * position;
    gl_Position = pos.xyzw;
    fragmentPosition = normalize(position);
}