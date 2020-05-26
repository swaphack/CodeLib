#version 330 core

uniform mat4 projectMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

layout(location = 0) in vec3 vPosition;

out vec3 fragmentUV;
out vec4 fragmentColor;

void main()
{
	vec4 position = vec4(vPosition, 1.0);
    vec4 pos = projectMatrix * viewMatrix * modelMatrix * position;
    gl_Position = pos.xyww;
    fragmentUV = vPosition;
}