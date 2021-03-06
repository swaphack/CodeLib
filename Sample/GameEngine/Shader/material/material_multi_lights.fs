#version 330 core

#include "Shader/core/frag/light.fs"
#include "Shader/core/frag/material.fs"
#include "Shader/core/frag/env.fs"
#include "Shader/core/frag/effect.fs"

uniform Light lights[MAX_LIGHT_COUNT];
uniform Material material;
uniform Environment env;

in vec2 fragTexcoord;
in vec3 fragNormal;
in vec3 fragPos;

out vec4 color;

void main()
{

	vec4 matColor = texture(material.tex, fragTexcoord);
	matColor = getGammaColor(env, matColor);

	vec3 viewDirection = normalize(env.viewPos - fragPos);

	color = get_mat_color_with_multi_lights(matColor, material, vec4(fragPos, 1.0), fragNormal, viewDirection, lights, env.lightCount);
}