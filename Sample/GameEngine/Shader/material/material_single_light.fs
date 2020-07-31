#version 330 core

#include "Shader/core/light.fs"
#include "Shader/core/material.fs"


uniform Light light;
uniform Material material;

uniform vec3 viewPos;

in vec2 fragTexcoord;
in vec3 fragNormal;
in vec3 fragPos;

out vec4 color;

void main()
{

	vec4 matColor = texture(material.texAmbient, fragTexcoord);

	vec3 viewDirection = normalize(viewPos - fragPos);

	Light lights[MAX_LIGHT_COUNT];
	lights[0] = light;

	color = get_mat_color_with_multi_lights(matColor, material, vec4(fragPos, 1.0), fragNormal, viewDirection, lights, 1);
}