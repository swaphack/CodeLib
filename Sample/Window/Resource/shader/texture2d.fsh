#version 330 core

in vec2 UV;
in vec4 Color;

out vec4 color;

uniform sampler2D texSampler;

void main()
{
	color = Color * texture(texSampler, UV);
}