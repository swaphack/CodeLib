#version 330 core

#include "Shader/core/matrix.vs"
#include "Shader/core/vertex.vs"

uniform Matrix matrix;

out vec3 fragPosition;

void main()
{
	vec4 pos = vec4(v_position, 1.0);
	gl_Position = matrix.project * matrix.view * pos;
    fragPosition = normalize(v_position);
}