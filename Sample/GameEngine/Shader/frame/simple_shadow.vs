#version 330 core

#include "Shader/core/vertex/light.vs"
#include "Shader/core/vertex/vertex.vs"
#include "Shader/core/vertex/matrix.vs"

uniform LightSpace lightSpace;
uniform Matrix matrix;

void main()
{
	gl_Position = lightSpace.spaceMattrix * matrix.model * vec4(v_position, 1.0);
}