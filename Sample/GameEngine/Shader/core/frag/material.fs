#include "Shader/core/frag/light.fs"

struct Material 
{
	vec4 emission; // 发射颜色
	vec4 ambient; // 环境颜色
	vec4 diffuse;	// 漫反射颜色
	vec4 specular; // 高光反射颜色

	sampler2D tex; // 纹理
	sampler2D texDiffuse; // 漫反射纹理
	sampler2D texSpecular; // 高光反射纹理
	sampler2D texAlpha;	// alpha纹理
	sampler2D texBump;	// bump纹理
	sampler2D texNormal;// normal纹理

	sampler2D texShadow; // 阴影纹理

	float shininess; 	// 镜面反射高光指数
	float strength;		// 镜面反射高光增强系数
};

// 环境
vec4 getMaterialAmbient(Light light,  Material material)
{
	return light.color * material.ambient;
}

// 漫反射
vec4 getMaterialDiffuse(Light light, Material material, vec3 fragNormal, vec3 fragPos)
{
	vec3 norm = normalize(fragNormal);
	vec3 lightDir;
	if (!light.isLocal) 
	{
		lightDir = light.direction;
	}
    else 
    {
    	lightDir = normalize(light.position - fragPos);
    }

    float diff = max(dot(norm, lightDir), 0.0);

    return (diff * material.diffuse); 
}
// 镜面反射
vec4 getMaterialSpecular(Light light, Material material, vec3 fragNormal, vec3 fragPos, vec3 viewPos)
{
	vec3 norm = normalize(fragNormal);
	vec3 lightDir;
	if (!light.isLocal) 
	{
		lightDir = light.direction;
	}
    else 
    {
    	lightDir = normalize(light.position - fragPos);
    }
	vec3 viewDir = normalize(viewPos - fragPos);

	//vec3 reflectDir = reflect(-lightDir, norm);

	vec3 halfwayDir = normalize(lightDir  + viewDir);  
    float spec = pow(max(dot(norm, halfwayDir), material.shininess), material.strength);

	//float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

	return (spec * material.specular);
}

// 阴影
float getMaterialShadowRatio(Light light, Material material, vec4 fragPosLightSpace, vec3 fragNormal, vec3 fragPos)
{
	vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;

	projCoords = projCoords * 0.5 + 0.5;

	float closestDepth = texture(material.texShadow, projCoords.xy).r;

	float currentDepth = projCoords.z;

	vec3 normal = normalize(fragNormal);
	vec3 lightDir = normalize(light.position - fragPos);

	float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.05);

	float shadow = 0.0;
	vec2 texelSize = 1.0 / textureSize(material.texShadow, 0);
	for (int x = -1; x <= 1; x++)
	{
		for (int y = -1; y <= 1; y++)
		{
			float pcfDepth = texture(material.texShadow, projCoords.xy + vec2(x, y) * texelSize).r;
			shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;
		}	
	}

	shadow /= 9.0;

	if (projCoords.z > 1.0)
	{
		shadow = 0;
	}

	return shadow;
}

// 环境
vec4 getMaterialAmbient(Light light,  Material material, vec2 fragTexcoord)
{
	return getMaterialAmbient(light, material) * texture(material.tex, fragTexcoord);
}
// 漫反射
vec4 getMaterialDiffuse(Light light, Material material, vec3 fragNormal, vec3 fragPos, vec2 fragTexcoord)
{
    return getMaterialDiffuse(light, material, fragNormal, fragPos) * texture(material.texDiffuse, fragTexcoord); 
}

// 镜面反射
vec4 getMaterialSpecular(Light light, Material material, vec3 fragNormal, vec3 fragPos, vec2 fragTexcoord, vec3 viewPos)
{
	return getMaterialSpecular(light, material, fragNormal, fragPos, viewPos) * texture(material.texSpecular, fragTexcoord);
}

// 计算多光源的材质颜色
vec4 get_mat_color_with_multi_lights(vec4 color, Material material, vec4 position, vec3 normal, vec3 viewDirection,
	Light lights[MAX_LIGHT_COUNT], int lightCount)
{
	vec4 scatteredLight = vec4(0.0);
	vec4 reflectedLight = vec4(0.0);

	if (lightCount > MAX_LIGHT_COUNT) lightCount = MAX_LIGHT_COUNT;

	for	(int i = 0; i < lightCount; i++)
	{
		if (!lights[i].isEnabled) continue;

		LightComputeProperty pro = computeLightProperty(lights[i], position, normal, viewDirection);

		if (pro.diffuse == 0.0)
		{
			pro.specular = 0.0;
		}
		else
		{
			pro.specular = pow(pro.specular, material.shininess) * material.strength;
		}

		scatteredLight += lights[i].color * material.ambient * pro.attenuation 
			+ lights[i].color * material.diffuse * pro.diffuse * pro.attenuation;

		reflectedLight += lights[i].color * material.specular * pro.specular * pro.attenuation;
	}

	vec4 result = min(color * scatteredLight + reflectedLight, vec4(1.0));

	return vec4(result.rgb, color.a);
}