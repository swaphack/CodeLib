#version 330 core

#include "Shader/core/frag/texture.fs"

uniform Texture tex;

in vec2 fragTexcoord;
in vec4 fragColor;

out vec4 color;

void main()
{
    // Output color = color of the texture at the specified UV
	vec4 c1 = texture(tex.texture0, fragTexcoord);
	vec4 c2 = texture(tex.texture1, fragTexcoord);

	color = fragColor * mix(c1, c2, 0.5f);
}