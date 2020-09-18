
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
    	-1.0, -1.0, -1.0,
    	-1.0, 8.0, -1.0,
    	-1.0, -1.0, -1.0
	);
    
   return getEffectColor(tex, uv, offsets, kernel);
}

