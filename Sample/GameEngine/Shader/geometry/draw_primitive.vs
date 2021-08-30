#version 330 core

#include "Shader/core/vertex/vertex.vs"
#include "Shader/core/vertex/matrix.vs"
#include "Shader/core/vertex/env.vs"

uniform Matrix matrix;
uniform Environment env;
out vec4 fragColor;

void main()
{
	setPointSize(env);
	gl_Position = getMVP(matrix) * vec4(v_position, 1.0);
	fragColor = v_color;
}