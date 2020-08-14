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