#version 330 core

struct Texture
{
	sampler2D texture0;
	sampler2D texture1;
	sampler2D texture2;
	/*
	sampler2D texture3;
	sampler2D texture4;
	sampler2D texture5;
	sampler2D texture6;
	sampler2D texture7;
	*/
};

struct Texture3D
{
	sampler3D texture0;
};

struct TextureCube
{
	samplerCube texture0;
};

uniform Texture tex;

in vec3 fragPosition;

out vec4 color;

void main()
{
	color = texture(tex.texture0, fragPosition);

	//color = vec4(fragPosition, 1.0);
}