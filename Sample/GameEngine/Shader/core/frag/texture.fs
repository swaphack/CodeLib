struct Texture
{
	sampler2D texture0; // ambient
	sampler2D texture1; // diffuse
	sampler2D texture2; // specular
	sampler2D texture3; // alpha
	sampler2D texture4; // bump
	sampler2D texture5; // normal
	sampler2D texture6; // shadow
	sampler2D texture7;
};

struct Texture3D
{
	sampler3D texture0;
};

struct TextureCube
{
	samplerCube texture0;
};