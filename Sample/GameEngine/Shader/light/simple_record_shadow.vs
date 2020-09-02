#version 330 core

#include "Shader/core/vertex/vertex.vs"
#include "Shader/core/vertex/matrix.vs"
#include "Shader/core/vertex/light.vs"

uniform Matrix matrix;
uniform LightSpace lightSpace;

void main()
{
	vec4 pos = vec4(v_position, 1.0);
	gl_Position = lightSpace.spaceMatrix * matrix.model * pos;

	//gl_Position = getMVP(matrix) * pos;
}