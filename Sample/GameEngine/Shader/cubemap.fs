#version 330 core

uniform samplerCube texSampler0;

in vec3 fragmentPosition;

out vec4 color;

void main()
{
	color = texture(texSampler0, fragmentPosition);

	//color = vec4(fragmentUV, 1.0);
}