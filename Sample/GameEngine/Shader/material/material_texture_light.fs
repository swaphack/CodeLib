#version 330 core

#include "Shader/core/frag/light.fs"
#include "Shader/core/frag/material.fs"

uniform Material material;
uniform float specularPercent;
uniform float diffusePercent;

in vec2 fragTexcoord;
in vec3 fragReflectDir;
in vec3 fargNormal;

out vec4 color;

void main()
{
	vec4 baseColor = texture(material.tex, fragTexcoord);

	//vec4 diffuseColor = texture(material.texDiffuse, normalize(fargNormal));
	//vec4 specularColor = texture(material.texSpecular, normalize(fragReflectDir));
	vec4 diffuseColor = texture(material.texDiffuse, fragTexcoord);
	vec4 specularColor = texture(material.texSpecular, fragTexcoord);
	vec4 c1 = mix(baseColor, diffuseColor * baseColor, diffusePercent);
	vec4 c2 = mix(c1, specularColor + c1, specularPercent);
	color = vec4(c2.rgb, baseColor.a);
}

