#version 330 core

#include "Shader/core/texture.fs"

uniform TextureCube tex;

in vec3 fragPosition;
in vec3 fragNormal;

out vec4 color;

void main()
{
	vec3 tc = reflect(-fragPosition, normalize(fragNormal));
	color = texture(tex.texture0, tc);
}