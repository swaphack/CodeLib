#version 330 core

#include "Shader/core/texture.fs"

uniform Texture tex;

in vec2 fragTexcoord;
in vec4 fragColor;

out vec4 color;

void main()
{

	vec4 c1 = fragColor * texture(tex.texture0, fragTexcoord);
	
	color = c1;
}