#version 330 core

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

uniform Matrix matrix;

uniform int furLayers = 30;
uniform float furDepth = 5.0;

layout (lines) in;
layout (triangle_strip, max_vertices=120) out;

void main()
{
	int i, layer;

	float delta = 1.0 / float(furLayers);
	float d = 0.0;

	for	(layer = 0; layer < furLayers; layer++)
	{
		vec4 norml;
		vec3 pos0 = (gl_in[1].gl_Position - gl_in[0].gl_Position).xyz;
		vec3 pos1 = gl_in[1].gl_Position.xyz;
		norml = cross(pos0, pos1);

		for	(i = 0; i < gl_in.length(); i++)
		{
			vec4 pos = gl_in[i].gl_Position;
			pos = pos + vec4 (norml * (1 - d) * d, 0.0);
			gl_Position = get_mvp(matrix) * pos;

			EmitVertex();
		}
		d+=delta;
		
		EndPrimitive();
	}
}