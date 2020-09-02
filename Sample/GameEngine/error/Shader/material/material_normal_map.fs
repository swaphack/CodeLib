#version 330 core

struct Light 
{
	bool isEnabled; // 是否启用
	bool isLocal;	// 是否为本地光源，否为方向光
	bool isSpot;	// 是否是锥形光源

	vec4 color;		// 光颜色

	vec3 position; 	// 位置
	vec3 direction; // 方向
	vec3 halfVector;	// 方向光的半向量

	mat4 spaceMatrix; 	// 光照方向的空间矩阵

	// 锥形光源属性
	float spotExponent;
	float spotCostCutoff;

	// 光照衰减系数
	float constantAttenuation;
	float linearAttenuation;
	float quadraticAttenuation;
};

// 光照计算值
struct LightComputeProperty
{
	vec3 halfVector;

	float attenuation;

	float diffuse;

	float specular;
};

const int MAX_LIGHT_COUNT = 8;

// 计算光照属性
LightComputeProperty computeLightProperty(Light light, vec4 position, vec3 normal, vec3 viewDirection)
{
	LightComputeProperty pro;

	vec3 lightDirection = light.direction;
	vec3 lightPosition = light.position;

	pro.attenuation = 1.0;

	if (light.isLocal)
	{
		lightDirection = lightPosition - vec3(position);
		float lightDistance = length(lightDirection);
		lightDirection = lightDirection / lightDistance;

		pro.attenuation = 1.0 / 
			(light.constantAttenuation 
				+ light.linearAttenuation * lightDistance
				+ light.quadraticAttenuation * lightDistance * lightDistance);

		if (light.isSpot)
		{
			float spotCos = dot(lightDirection, - light.direction);
			if (spotCos < light.spotCostCutoff)
			{
				pro.attenuation = 0.0;
			}
			else
			{
				pro.attenuation *= pow(spotCos, light.spotExponent);
			}
		}

		pro.halfVector = normalize(lightDirection + viewDirection);
	}
	else
	{
		pro.halfVector = light.halfVector;
	}

	pro.diffuse = max(0.0, dot(lightDirection, normal));
	pro.specular = max(0.0, dot(normal, pro.halfVector));

	return pro;
}

// 计算光照颜色
vec4 getMultiLightsColor(vec4 color, vec4 position, vec3 normal, vec3 viewDirection, 
	float shininess, float strength,
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
			pro.specular = pow(pro.specular, shininess) * strength;
		}

		scatteredLight += lights[i].color * pro.attenuation 
			+ lights[i].color * pro.diffuse * pro.attenuation;

		reflectedLight += lights[i].color * pro.specular * pro.attenuation;
	}

	vec4 result = min(color * scatteredLight + reflectedLight, vec4(1.0));

	return vec4(result.rgb, color.a);
}


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

	sampler2DShadow texShadow; // 阴影纹理

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

	float closestDepth = shadow(material.texShadow, projCoords.xy).r;

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
			float pcfDepth = shadow(material.texShadow, projCoords.xy + vec2(x, y) * texelSize).r;
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

	vec4 result = min(material.emission + color * scatteredLight + reflectedLight, vec4(1.0));

	return vec4(result.rgb, color.a);
}
// 环境
struct Environment 
{
	vec3 viewPos;	// 视角位置
	int lightCount; // 光源数量
	float gamma;	// gamma值
	float pointSize; // 点大小
};

// gamma
vec4 getGammaColor(Environment env, vec4 color)
{
    if (env.gamma != 0)
    {
        vec3 rgb = color.rgb;
        rgb = pow(rgb, vec3(1 / env.gamma));
        color = vec4(rgb, color.a);
    }

    return color;
}



// 反转
vec4 getInversionEffect(vec4 color)
{
	return vec4(vec3(1.0 - color.xyz), 1.0);
}

// 灰色
vec4 getGrayScaleEffect(vec4 color)
{
	float avarage = 0.2126 * color.r +  0.7152 * color.g + 0.0722 * color.b;
	return vec4(avarage, avarage, avarage, 1.0);
}

// 偏移量
vec2[9] getOffsets(float offset)
{
	return vec2[](
        vec2(-offset,  offset), // top-left
        vec2( 0.0f,    offset), // top-center
        vec2( offset,  offset), // top-right
        vec2(-offset,  0.0f),   // center-left
        vec2( 0.0f,    0.0f),   // center-center
        vec2( offset,  0.0f),   // center-right
        vec2(-offset, -offset), // bottom-left
        vec2( 0.0f,   -offset), // bottom-center
        vec2( offset, -offset)  // bottom-right    
    );
}

// 偏移量
vec4 getEffectColor(sampler2D tex, vec2 uv, vec2 offsets[9], float kernel[9])
{
	vec3 sampleTex[9];
    for(int i = 0; i < 9; i++)
    {
        sampleTex[i] = vec3(texture(tex, uv + offsets[i]));
    }
    vec3 col = vec3(0.0);
    for(int i = 0; i < 9; i++)
        col += sampleTex[i] * kernel[i];
    
    return vec4(col, 1.0);
}

// 硬核
vec4 getKernelEffect(float offset, sampler2D tex, vec2 uv)
{
	vec2 offsets[9] = getOffsets(offset);

    float kernel[9] = float[](
        -1, -1, -1,
        -1,  9, -1,
        -1, -1, -1
    );
    
    return getEffectColor(tex, uv, offsets, kernel);
}

// 模糊
vec4 getBlurEffect(float offset, sampler2D tex, vec2 uv)
{
	vec2 offsets[9] = getOffsets(offset);
	
    float kernel[9] = float[](
    	1.0 / 16, 2.0 / 16, 1.0 / 16,
    	2.0 / 16, 4.0 / 16, 2.0 / 16,
    	1.0 / 16, 2.0 / 16, 1.0 / 16  
	);
    
   return getEffectColor(tex, uv, offsets, kernel);
}

// 边缘
vec4 getEdgeEffect(float offset, sampler2D tex, vec2 uv)
{
	vec2 offsets[9] = getOffsets(offset);
	
    float kernel[9] = float[](
    	1.0, 1.0, 1.0,
    	1.0, -8.0, 1.0,
    	1.0, 1.0, 1.0
	);
    
   return getEffectColor(tex, uv, offsets, kernel);
}



uniform Light lights[MAX_LIGHT_COUNT];
uniform Material material;
uniform Environment env;

in vec2 fragTexcoord;
in vec3 fragPos;
in mat3 fragTBN;

out vec4 color;

void main()
{
	vec3 normal = texture(material.texNormal, fragTexcoord).rgb;
	vec3 fragNormal = normalize(normal* 2.0 - 1.0);

	vec4 matColor = texture(material.tex, fragTexcoord);
	matColor = getGammaColor(env, matColor);

	vec3 viewPos = fragTBN * env.viewPos;
	vec3 viewDirection = normalize(viewPos - fragPos);
	int lightCount = env.lightCount;

	Light tempLights[MAX_LIGHT_COUNT];
	for (int i = 0; i < lightCount; i++)
	{
		tempLights[i] = lights[i];
		tempLights[i].position = fragTBN * tempLights[i].position;
	}

	color = get_mat_color_with_multi_lights(matColor, material, vec4(fragPos, 1.0), fragNormal, viewDirection, lights, lightCount);
}