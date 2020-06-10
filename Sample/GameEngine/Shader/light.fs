
#version 330 core

uniform vec4 lightColor;

out vec4 color;

void main()
{
	color = lightColor;
}