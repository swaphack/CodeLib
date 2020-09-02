#version 330 core

#include "Shader/core/frag/light.fs"
#include "Shader/core/frag/material.fs"
#include "Shader/core/frag/env.fs"

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
	vec4 matColor = texture(material.tex, fragTexcoord);
	vec3 normal = normalize(fragNormal);

	vec4 ambient = getMaterialAmbient(light, material);

	vec4 diffuse = getMaterialDiffuse(light, material, normal, fragPosition);

	vec4 specular = getMaterialSpecular(light, material, normal, fragPosition, env.viewPos);

	float shadow = getMaterialShadowRatio(light, material, fragPosLightSpace, normal, fragPosition);

	vec4 lighting = (ambient + (1.0 - shadow) * (diffuse + specular)) * matColor;

	color = vec4(lighting.rgb, matColor.a);

}