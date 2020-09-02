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
mat4 getMVP(Matrix matrix) 
{
	return matrix.project * matrix.view * matrix.model;
	//return matrix.mvp;
}

// 模型-视图 矩阵
mat4 getMV(Matrix matrix) 
{
	return matrix.view * matrix.model;
	//return matrix.mv;
}

// 变换后的法线
vec3 getTransposeNormal(mat3 normalMatrix, vec3 normal)
{
	return normalize(normalMatrix * normal);
}

uniform Matrix matrix;
uniform LightSpace lightSpace;

void main()
{
	vec4 pos = vec4(v_position, 1.0);
	gl_Position = lightSpace.spaceMatrix * matrix.model * pos;
}