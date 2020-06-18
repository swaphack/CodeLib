#version 330 core

in float intensity;

out vec4 color;

void main()
{
	color = mix(
		vec4(0.0f, 0.2f, 1.0, 1.0),
		vec4(0.2f, 0.05, 0.0, 1.0),
		intensity
	);
}