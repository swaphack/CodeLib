
#version 330 core

#include "Shader/core/frag/light.fs"

uniform Light light;

out vec4 color;

void main()
{
	color = light.color;
}