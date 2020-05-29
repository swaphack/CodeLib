#version 330 core

uniform mat4 projectMatrix;
uniform mat4 modelMatrix;

layout (location=0) in vec3 vPosition;
layout (location=1) in vec3 vNormal;

 //输出
out vec3 worldSpacePosition;
out vec3 fragmentNormal;

void main(void)
{
	vec4 position = modelMatrix * vec4(vPosition, 1.0);
	worldSpacePosition = position.xyz;

    fragmentNormal = normalize((modelMatrix * vec4(vNormal, 0)).xyz);
    
    gl_Position = projectMatrix * position;
}