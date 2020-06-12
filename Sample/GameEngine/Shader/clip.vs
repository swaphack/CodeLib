#version 450 core

uniform vec4 Plane;
uniform mat4 projectMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec4 vColor;
layout(location = 2) in vec2 vUV;


out vec2 fragTexcoord;
out vec4 fragColor;

float gl_ClipDistance[1];

void main()
{
	vec4 position = vec4(vPosition,1);
    gl_Position = projectMatrix * viewMatrix * modelMatrix * position;
    fragTexcoord = vUV;
    fragColor = vColor;	

	gl_ClipDistance[0] = dot(position, Plane);
}