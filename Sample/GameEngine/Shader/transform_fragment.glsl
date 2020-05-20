#version 410

in vec3 fragmentNormal;

out vec4 color;

void main()
{
	 color = vec4(0.0, 0.2, 0.0, 1.0) + vec4(0.2, 0.5, 0.4, 1.0) * abs(fragmentNormal.z) + vec4(0.8, 0.9, 0.7, 1.0) * pow(abs(fragmentNormal.z), 70.0);
}