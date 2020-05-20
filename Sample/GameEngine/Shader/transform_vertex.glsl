#version 420 core

uniform mat4 modelMatrix;
uniform mat4 projectMatrix;

layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vNormal;

out vec4 worldSpacePosition;
out vec3 fragmentNormal;

void main()
{
	vec4 pos = modelMatrix * vec4(vPosition, 1.0);
	gl_Position = projectMatrix * pos;

	worldSpacePosition = pos;
	fragmentNormal = normalize((modelMatrix* vec4(vNormal, 0.0)).xyz);
}