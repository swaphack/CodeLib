#version 330 core

uniform mat4 projectMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

layout(location = 0) in vec3 vPosition;
layout(location = 7) in vec3 vNormal;

out vec3 fragmentPosition;
out vec3 fragmentNormal;

void main()
{
	vec4 pos = vec4(vPosition, 1);
	mat4 mvp = projectMatrix * viewMatrix * modelMatrix;
	mat4 mv = viewMatrix * modelMatrix;

	gl_Position = mvp * pos;

	fragmentNormal = mat3(mv) * vNormal;
	fragmentPosition = (mv * pos).xyz;
}