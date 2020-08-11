#version 330 core

#include "Shader/core/light.vs"
#include "Shader/core/vertex.vs"
#include "Shader/core/matrix.vs"

uniform LightSpace lightSpace;
uniform Matrix matrix;

void main()
{
	gl_Position = lightSpace.spaceMattrix * matrix.model * vec4(v_position, 1.0);
}