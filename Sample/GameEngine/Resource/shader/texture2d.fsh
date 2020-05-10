#version 330 core

in vec2 UV;
in vec4 Color;

out vec4 color;

uniform sampler2D texSampler0;

void main()
{
	color = Color * texture(texSampler0, UV);
}