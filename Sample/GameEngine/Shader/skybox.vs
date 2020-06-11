#version 330 core

#include "Shader/vertex/matrix.vs"
#include "Shader/vertex/vertex.vs"

uniform Matrix matrix;

out vec3 fragmentPosition;

void main()
{
	vec4 pos = vec4(v_position, 1.0);
	gl_Position = matrix.project * matrix.view * pos;
    fragmentPosition = normalize(v_position);
}