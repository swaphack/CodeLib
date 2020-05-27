#version 330 core

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectMatrix;

layout (location = 0) in vec3 vPosition;
layout (location = 2) in vec2 vUV;

out vec2 fragmentUV;

void main()
{
	vec4 pos = vec4(vPosition, 1.0);
	gl_Position = projectMatrix * viewMatrix * modelMatrix * pos;

    fragmentUV = vUV;
}