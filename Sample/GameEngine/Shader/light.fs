
#version 330 core

#include "Shader/fragment/light.fs"

uniform Light light;

out vec4 color;

void main()
{
	color = light.ambient;
}