#version 330 core

uniform mat4 projectMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

uniform float pointScale;

layout(location=0) in vec3 vPosition;

void main()
{
	vec4 pos = vec4(vPosition, 1.0);
	pos = projectMatrix * viewMatrix * modelMatrix * pos;
	gl_PointSize = gl_PointSize * pointScale;
	gl_Position = pos;
}