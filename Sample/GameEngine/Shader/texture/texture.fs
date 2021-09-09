#version 330 core

#include "Shader/core/frag/texture.fs"
#include "Shader/core/frag/effect.fs"

uniform Texture tex;

in vec2 fragTexcoord;
in vec4 fragColor;
out vec4 color;

void main()
{
	color = fragColor * texture(tex.texture0, fragTexcoord);
}