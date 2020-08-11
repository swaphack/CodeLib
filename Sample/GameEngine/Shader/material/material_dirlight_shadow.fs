#version 330 core

#include "Shader/core/light.fs"
#include "Shader/core/material.fs"
#include "Shader/core/env.fs"

uniform Light light;
uniform Material material;
uniform Environment env;

in vec2 fragTexcoord;
in vec3 fragPosition;
in vec3 fragNormal;
in vec4 fragPosLightSpace;

out vec4 color;

void main()
{
	vec3 matColor = texture(material.tex, fragTexcoord).rgb;
	vec3 normal = normalize(fragNormal);

	vec4 ambient = get_mat_ambient(light, material);

	vec4 diffuse = get_mat_diffuse(light, material, fragNormal, fragPosition);

	vec4 specular = get_mat_specular(light, material, fragNormal, fragPosition, env.viewPos);

	float shadow = get_mat_shadow_ratio(light, material, fragPosLightSpace, fragNormal, fragPosition);

	vec4 lighting = (ambient + (1.0 - shadow) * (diffuse + specular)) * color;

	color = vec4(lighting.rgb, color.a);

}