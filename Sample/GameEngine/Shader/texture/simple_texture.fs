#version 330 core

#include "Shader/core/light.fs"


uniform Light light;
uniform Material material;

uniform sampler2D texSampler0;

in vec2 fragTexcoord;
in vec3 fragNormal;
in vec3 fragPos;

uniform vec3 lightPos;
uniform vec3 viewPos;

out vec4 color;

void main()
{
	// ambient
	vec4 ambient = get_mat_ambient(light, material, fragTexcoord);

	// diffuse
	vec4 diffuse = get_mat_diffuse(light, material, fragNormal, fragPos, fragTexcoord);

	// specular
	vec4 specular = get_mat_specular(light, material, fragNormal, fragPos, fragTexcoord, viewPos);

	//vec4 texColor = texture(texSampler0, fragTexcoord);

	vec4 result = (ambient + diffuse + specular) ;

	color = result;
}