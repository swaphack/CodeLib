#version 330 core

in vec4 Color;

out vec3 color;

void main()
{
    color = Color.rgb;
}