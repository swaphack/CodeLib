#version 330 core

uniform mat4 projMat;
uniform mat4 viewMat;
uniform mat4 modelMat;

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec4 vertexColor;
layout(location = 2) in vec2 vertexUV;

out vec2 UV;
out vec4 Color;

void main()
{
    gl_Position = projMat * viewMat * modelMat * vec4(vertexPosition,1);
    UV = vertexUV;
	Color = vertexColor;
}