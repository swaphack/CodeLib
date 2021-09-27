#version 330 core

layout(location = 0) in vec3 v_position;
layout(location = 1) in vec4 v_color;

struct Matrix 
{
	mat4 project;	// 投影矩阵
	mat4 view;		// 视图矩阵
	mat4 model;		// 模型矩阵
};

uniform Matrix matrix;

out vec4 fragColor;

void main()
{
    fragColor = v_color;

    vec4 pos = vec4(v_position, 1.0);
    gl_Position = matrix.project * matrix.view * matrix.model * pos;
}