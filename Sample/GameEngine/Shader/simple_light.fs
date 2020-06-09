#version 330 core

uniform sampler2D texSampler0;

uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

in vec2 fragmentUV;
in vec3 fragmentNormal;
in vec3 fragmentPos;


out vec4 color;

void main()
{
	// ambient
	vec4 ambient = vec4(lightColor);

	// diffuse
	vec3 norm = normalize(fragmentNormal);
	vec3 lightDir = normalize(lightPos - fragmentPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec4 diffuse = diff * lightColor;

	// specular
	vec3 viewDir = normalize(viewPos - fragmentPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec4 specular = spec * lightColor;

	vec4 texColor = texture(texSampler0, fragmentUV);
	vec4 result = (ambient + diffuse + specular) * texColor;
	color = result;
}