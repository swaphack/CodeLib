#version 330 core

#include "Shader/core/frag/light.fs"
#include "Shader/core/frag/material.fs"
#include "Shader/core/frag/env.fs"

uniform Light light;
uniform Material material;

uniform Environment env;

in vec2 fragTexcoord;
in vec3 fragNormal;
in vec3 fragPos;

out vec4 color;

void main()
{

	vec4 matColor = texture(material.tex, fragTexcoord);

	vec3 viewDirection = normalize(env.viewPos - fragPos);

	Light lights[MAX_LIGHT_COUNT];
	lights[0] = light;

	color = get_mat_color_with_multi_lights(matColor, material, vec4(fragPos, 1.0), fragNormal, viewDirection, lights, 1);
}