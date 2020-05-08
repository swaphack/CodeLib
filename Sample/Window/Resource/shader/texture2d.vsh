#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec4 vertexColor;
layout(location = 2) in vec2 vertexUV;

// Output data ; will be interpolated for each fragment.
out vec2 UV;

out vec4 Color;

void main(){

    // Output position of the vertex, in clip space : MVP * position
    gl_Position = vec4(vertexPosition,1);

    // UV of the vertex. No special space for this one.
    UV = vertexUV;

	Color = vertexColor;
}