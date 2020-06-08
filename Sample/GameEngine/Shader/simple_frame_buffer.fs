#version 330 core

uniform sampler2D texSampler0;

in vec2 fragmentUV;

out vec4 color;

void main()
{
	color = texture(texSampler0, fragmentUV);
	//color = vec4(1.0, 0, 0, 1);
	//color = vec4(vec3(1.0 - texture(texSampler0, fragmentUV)), 1.0);
}