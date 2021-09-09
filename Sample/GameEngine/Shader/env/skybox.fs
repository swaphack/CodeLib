#version 330 core

#include "Shader/core/frag/texture.fs"

uniform TextureCube tex;

in vec3 fragPosition;

out vec4 color;

void main()
{
	color = texture(tex.texture0, fragPosition);

	//color = vec4(fragTexcoord, 1.0);
}