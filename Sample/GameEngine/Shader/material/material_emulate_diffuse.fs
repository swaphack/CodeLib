#version 330 core

#include "Shader/core/frag/material.fs"

uniform Material material;

in vec3 fragColor;
in vec2 fragTexcoord;

out vec4 color;

void main()
{
	vec4 matColor = texture(material.tex, fragTexcoord);

	color.rgb = matColor.rgb + fragColor;
	color.a = matColor.a;
}