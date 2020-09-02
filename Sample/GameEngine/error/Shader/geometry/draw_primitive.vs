#version 330 core

layout(location = 0) in vec3 v_position;
layout(location = 1) in vec4 v_color;
layout(location = 2) in vec2 v_texcoord;
layout(location = 3) in vec3 v_normal;
layout(location = 4) in vec3 v_tangent;
layout(location = 5) in vec3 v_bitangent;
layout(location = 6) in vec2 v_texcoord1;
layout(location = 7) in vec2 v_texcoord2;
layout(location = 8) in vec2 v_texcoord3;
layout(location = 9) in vec2 v_texcoord4;

struct Matrix 
{
	mat4 project;	
	mat4 view;
	mat4 model;
	mat3 normal;
	mat4 mvp;
	mat4 mv;
};

// 模型-视图-透视 矩阵
mat4 get_mvp(Matrix matrix) 
{
	return matrix.project * matrix.view * matrix.model;
	//return matrix.mvp;
}

// 模型-视图 矩阵
mat4 get_mv(Matrix matrix) 
{
	return matrix.view * matrix.model;
	//return matrix.mv;
}

// 变换后的法线
vec3 getTransposeNormal(mat3 normalMatrix, vec3 normal)
{
	return normalize(normalMatrix * normal);
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
    if (gamma != 0)
    {
        vec3 rgb = color.rgb;
        rgb = pow(rgb, vec3(1 / gamma));
        color = vec4(rgb, color.a);
    }

    return color;
}

void setPointSize(Environment env)
{
	gl_PointSize = env;
}

uniform Matrix matrix;
uniform Environment env;

void main()
{
	setPointSize(env);
	gl_Position = get_mvp(matrix) * vec4(v_position, 1.0);
}