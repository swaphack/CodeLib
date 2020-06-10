#include "Shader/vertex/matrix.vs"

#version 330 core

layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec4 vColor;
layout(location = 2) in vec2 vUV;

out vec2 fragmentUV;
out vec4 fragmentColor;

void main()
{
	vec4 position = vec4(vPosition, 1.0);
    gl_Position = MVP * position;
    fragmentUV = vUV;
    fragmentColor = vColor;	
}