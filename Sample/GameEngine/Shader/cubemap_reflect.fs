#version 330 core



uniform samplerCube texSampler0;

in vec3 fragmentPosition;
in vec3 fragmentNormal;

out vec4 color;

void main()
{
	vec3 tc = reflect(-fragmentPosition, normalize(fragmentNormal));
	color = texture(texSampler0, tc);
}