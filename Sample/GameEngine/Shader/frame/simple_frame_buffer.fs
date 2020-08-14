#version 330 core

#include "Shader/core/frag/texture.fs"
#include "Shader/core/frag/effect.fs"

uniform Texture tex;

in vec2 fragTexcoord;

out vec4 color;

void main()
{
	color = texture(tex.texture0, fragTexcoord);


	color = getKernelEffect(0.01, tex.texture0, fragTexcoord);
	//color = vec4(1.0, 0, 0, 1);
	//color = vec4(vec3(1.0 - texture(tex.texture0, fragTexcoord)), 1.0);
}