#version 330 core

struct Material {
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	float shininess;
};

uniform Material material;

uniform sampler2D texSampler0;

uniform vec4 lightColor;


in vec2 fragmentUV;
in vec3 fragmentNormal;
in vec3 fragmentPos;

uniform vec3 lightPos;
uniform vec3 viewPos;


out vec4 color;

void main()
{
	// ambient
	vec4 ambient = lightColor * material.ambient;

	// diffuse
	vec3 norm = normalize(fragmentNormal);
	vec3 lightDir = normalize(lightPos - fragmentPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec4 diffuse = lightColor * (diff * material.diffuse);

	// specular
	vec3 viewDir = normalize(viewPos - fragmentPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec4 specular = lightColor * (spec * material.specular);

	vec4 texColor = texture(texSampler0, fragmentUV);
	vec4 result = (ambient + diffuse + specular) * texColor;
	color = result;
}