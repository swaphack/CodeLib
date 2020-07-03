#include "Shader/core/light.fs"

struct Material 
{
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;

	sampler2D texAmbient;
	sampler2D texDiffuse;
	sampler2D texSpecular;

	float shininess;
};

// 环境
vec4 get_mat_ambient(Light light,  Material material)
{
	return light.ambient * material.ambient;
}
// 漫反射
vec4 get_mat_diffuse(Light light, Material material, vec3 fragNormal, vec3 fragPos)
{
	vec3 norm = normalize(fragNormal);

    vec3 lightDir = normalize(light.position - fragPos);

    float diff = max(dot(norm, lightDir), 0.0);

    return light.diffuse * (diff * material.diffuse); 
}
// 镜面反射
vec4 get_mat_specular(Light light, Material material, vec3 fragNormal, vec3 fragPos, vec3 viewPos)
{
	vec3 norm = normalize(fragNormal);

	vec3 lightDir = normalize(light.position - fragPos);
	vec3 viewDir = normalize(viewPos - fragPos);

	vec3 reflectDir = reflect(-lightDir, norm);

	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

	return light.specular * (spec * material.specular);
}

// 环境
vec4 get_mat_ambient(Light light,  Material material, vec2 fragTexcoord)
{
	return get_mat_ambient(light, material) * texture(material.texAmbient, fragTexcoord);
}
// 漫反射
vec4 get_mat_diffuse(Light light, Material material, vec3 fragNormal, vec3 fragPos, vec2 fragTexcoord)
{
    return get_mat_diffuse(light, material, fragNormal, fragPos) * texture(material.texDiffuse, fragTexcoord); 
}

// 镜面反射
vec4 get_mat_specular(Light light, Material material, vec3 fragNormal, vec3 fragPos, vec2 fragTexcoord, vec3 viewPos)
{
	return get_mat_specular(light, material, fragNormal, fragPos, viewPos) * texture(material.texSpecular, fragTexcoord);
}