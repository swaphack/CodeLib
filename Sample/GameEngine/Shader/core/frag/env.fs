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

