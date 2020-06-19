#version 330 core

#include "Shader/core/matrix.vs"

layout(location = 0) in vec4 v_position;

uniform Matrix matrix;

out float intensity;

void main()
{
	intensity = v_position.w;
	gl_Position = get_mvp(matrix) * vec4(v_position.xyz, 1.0);
}