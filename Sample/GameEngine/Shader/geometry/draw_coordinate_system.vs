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
	fragColor = v_color;
	gl_Position = getMVP(matrix) * vec4(v_position, 1.0);
}