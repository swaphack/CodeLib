#version 330 core

subroutine vec4 LightFunc(vec3);

subroutine (LightFunc) vec4 ambient(vec3 n)
{
	return vec4(n, 1);
}

subroutine (LightFunc) vec4 diffuse(vec3 n)
{
	return vec4(n, 1);
}

subroutine uniform LightFunc materialShader;