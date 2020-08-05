#version 330 core

#include "Shader/core/light.fs"
#include "Shader/core/material.fs"


uniform Light lights[MAX_LIGHT_COUNT];
uniform Material material;
uniform int lightCount;

uniform vec3 viewPos;

in vec2 fragTexcoord;
in vec3 fragNormal;
in vec3 fragPos;

out vec4 color;

void main()
{

	vec4 matColor = texture(material.tex, fragTexcoord);

	vec3 viewDirection = normalize(viewPos - fragPos);

	color = get_mat_color_with_multi_lights(matColor, material, vec4(fragPos, 1.0), fragNormal, viewDirection, lights, lightCount);
}