#version 330 core

#include "Shader/fragment/light.fs"


uniform Light light;
uniform Material material;

uniform sampler2D texSampler0;

in vec2 fragmentUV;
in vec3 fragmentNormal;
in vec3 fragmentPos;

uniform vec3 lightPos;
uniform vec3 viewPos;

out vec4 color;

void main()
{
	// ambient
	vec4 ambient = get_mat_ambient(light, material, fragmentUV);

	// diffuse
	vec4 diffuse = get_mat_diffuse(light, material, fragmentNormal, fragmentPos, fragmentUV);

	// specular
	vec4 specular = get_mat_specular(light, material, fragmentNormal, fragmentPos, fragmentUV, viewPos);

	//vec4 texColor = texture(texSampler0, fragmentUV);

	vec4 result = (ambient + diffuse + specular) ;

	color = result;
}