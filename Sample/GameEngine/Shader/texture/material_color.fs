#version 330 core

#include "Shader/core/light.fs"


uniform Light light;
uniform Material material;

uniform vec3 lightPos;
uniform vec3 viewPos;

in vec3 fragNormal;
in vec3 fragPos;

out vec4 color;

void main()
{
	// ambient
	vec4 ambient = get_mat_ambient(light, material);

	// diffuse
	vec4 diffuse = get_mat_diffuse(light, material, fragNormal, fragPos);

	// specular
	vec4 specular = get_mat_specular(light, material, fragNormal, fragPos, viewPos);

	vec4 result = (ambient + diffuse + specular) ;

	color = result;
}