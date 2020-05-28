#version 330 core

uniform samplerCube texSampler0;

in vec3 fragmentUV;

out vec4 color;

void main()
{
	color = texture(texSampler0, fragmentUV);

	color = vec4(1,1,1,1);
}