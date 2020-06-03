#version 330 core

layout(location=0) in vec2 vPosition;
layout(location=2) in vec2 vUV;

out vec2 fragmentUV;

void main()
{
	gl_Position = vec4(vPosition.x, vPosition.y, 0, 1.0);
	fragmentUV = vUV;
}