#version 330 core

#include "Shader/core/frag/light.fs"
#include "Shader/core/frag/material.fs"
#include "Shader/core/frag/env.fs"
#include "Shader/core/frag/effect.fs"

uniform Light lights[MAX_LIGHT_COUNT];
uniform Material material;
uniform Environment env;

in vec2 fragTexcoord;
in vec3 fragPos;
in mat3 fragTBN;

out vec4 color;

void main()
{
	vec3 normal = texture(material.texNormal, fragTexcoord).rgb;
	vec3 fragNormal = normalize(normal* 2.0 - 1.0);

	vec4 matColor = texture(material.tex, fragTexcoord);
	matColor = getGammaColor(env, matColor);

	vec3 viewPos = fragTBN * env.viewPos;
	vec3 viewDirection = normalize(viewPos - fragPos);
	int lightCount = env.lightCount;

	Light tempLights[MAX_LIGHT_COUNT];
	for (int i = 0; i < lightCount; i++)
	{
		tempLights[i] = lights[i];
		tempLights[i].position = fragTBN * tempLights[i].position;
	}

	color = get_mat_color_with_multi_lights(matColor, material, vec4(fragPos, 1.0), fragNormal, viewDirection, lights, lightCount);
}