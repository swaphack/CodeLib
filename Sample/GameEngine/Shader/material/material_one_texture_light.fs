#version 330 core

#include "Shader/core/light.fs"
#include "Shader/core/material.fs"
#include "Shader/core/env.fs"

uniform Light light;
uniform Material material;
uniform Environment env;

in vec2 fragTexcoord;
in vec3 fragNormal;
in vec3 fragPos;

out vec4 color;

void main()
{
	// ambient
	vec4 ambient = get_mat_ambient(light, material) * texture(material.tex, fragTexcoord);

	// diffuse
	vec4 diffuse = get_mat_diffuse(light, material, fragNormal, fragPos) * texture(material.tex, fragTexcoord);

	// specular
	vec4 specular = get_mat_specular(light, material, fragNormal, fragPos, env.viewPos) * texture(material.tex, fragTexcoord);

	//diffuse = vec4(0.0);
	//specular = vec4(0.0);

	vec4 result = material.emission + (ambient + diffuse + specular) ;

	color = result;
}