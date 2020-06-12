#version 330 core

#include "Shader/core/texture.fs"

uniform Texture tex;

in vec3 fragPosition;

out vec4 color;

void main()
{
	color = texture(tex.texture0, fragPosition);

	//color = vec4(fragPosition, 1.0);
}