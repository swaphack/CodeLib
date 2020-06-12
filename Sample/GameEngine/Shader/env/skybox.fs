#version 330 core

#include "Shader/core/texture.fs"

uniform Texture3D tex;

in vec3 fragPosition;

out vec4 color;

void main()
{
	color = texture(tex.texture0, fragPosition);

	//color = vec4(fragTexcoord, 1.0);
}