#version 330 core

uniform mat4 projectMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

layout(location = 0) in vec3 vPosition;
layout(location = 2) in vec2 vUV;
layout(location = 7) in vec3 vNormal;

out vec2 fragmentUV;
out vec3 fragmentNormal;
out vec3 fragmentPos;

void main()
{
	vec4 position = vec4(vPosition, 1.0);

	fragmentPos = vec3(modelMatrix * position);
    fragmentUV = vUV;
    fragmentNormal = vNormal;

    gl_Position = projectMatrix * viewMatrix * modelMatrix * position;
}