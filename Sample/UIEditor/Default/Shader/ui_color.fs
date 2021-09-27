#version 330 core

in vec4 fragColor;

out vec4 color;

void main()
{	
	color = fragColor;
	color = vec4(1,1,1,1);
}