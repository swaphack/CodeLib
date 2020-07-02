#version 330 core

#include "Shader/core/texture.fs"
#include "Shader/core/effect.fs"

uniform Texture tex;

in vec2 fragTexcoord;

out vec4 color;

void main()
{
	color = texture(tex.texture0, fragTexcoord);
}