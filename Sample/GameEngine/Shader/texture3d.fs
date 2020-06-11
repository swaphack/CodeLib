#version 330 core

uniform sampler2D texSampler0;

in vec2 fragmentUV;
in vec4 fragmentColor;

out vec4 color;

void main()
{

	vec4 c1 = fragmentColor * texture(texSampler0, fragmentUV);
	
	color = c1;
}