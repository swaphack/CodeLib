#version 330 core

struct Texture
{
	sampler2D texture0;
	sampler2D texture1;
};

uniform Texture tex;

in vec2 fragTexcoord;
in vec4 fragColor;

out vec4 color;

void main()
{
	vec4 c1 = fragColor * texture(tex.texture0, fragTexcoord);
	
	color = c1;
	color = vec(1, 0, 1, 1);
}