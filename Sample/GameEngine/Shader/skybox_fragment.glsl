#version 330 core



uniform samplerCube texSampler0;

in vec3 fragmentUV;

out vec4 color;

void main()
{

	vec4 c1 = texture(texSampler0, fragmentUV);
	
	color = c1;
}