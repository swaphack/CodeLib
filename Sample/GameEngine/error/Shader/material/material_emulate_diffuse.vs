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
layout(location = 0) in vec3 v_position;
layout(location = 1) in vec4 v_color;
layout(location = 2) in vec2 v_texcoord;
layout(location = 3) in vec2 v_texcoord1;
layout(location = 4) in vec2 v_texcoord2;
layout(location = 5) in vec2 v_texcoord3;
layout(location = 6) in vec2 v_texcoord4;
layout(location = 7) in vec3 v_normal;
// 模拟光照

const float EMULATE_LIGHT_DIFFUSE_PARAMETER1 = 0.429043;
const float EMULATE_LIGHT_DIFFUSE_PARAMETER2 = 0.511664;
const float EMULATE_LIGHT_DIFFUSE_PARAMETER3 = 0.743125;
const float EMULATE_LIGHT_DIFFUSE_PARAMETER4 = 0.886227;
const float EMULATE_LIGHT_DIFFUSE_PARAMETER5 = 0.247708;

const vec3 EMULATE_LIGHT_OLD_TOWN_SQUARE_L00 = vec3(0.871, 0.875, 0.864);
const vec3 EMULATE_LIGHT_OLD_TOWN_SQUARE_L1m1 = vec3(0.175, 0.245, 0.313);
const vec3 EMULATE_LIGHT_OLD_TOWN_SQUARE_L10 = vec3(0.034, 0.036, 0.037);
const vec3 EMULATE_LIGHT_OLD_TOWN_SQUARE_L11 = vec3(-0.005, -0.029, -0.048);
const vec3 EMULATE_LIGHT_OLD_TOWN_SQUARE_L2m2 = vec3(-0.121, -0.121, -0.118);
const vec3 EMULATE_LIGHT_OLD_TOWN_SQUARE_L2m1 = vec3(0.003, 0.003, 0.008);
const vec3 EMULATE_LIGHT_OLD_TOWN_SQUARE_L20 = vec3(-0.029, -0.249, -0.021);
const vec3 EMULATE_LIGHT_OLD_TOWN_SQUARE_L21 = vec3(-0.078, -0.087, -0.092);
const vec3 EMULATE_LIGHT_OLD_TOWN_SQUARE_L22 = vec3(-0.162, -0.192, -0.219);

vec3 getLightOldTownEmulateDiffuseLight(vec3 normal)
{

	vec3 color = EMULATE_LIGHT_DIFFUSE_PARAMETER1 * EMULATE_LIGHT_OLD_TOWN_SQUARE_L22 * (normal.x * normal.x - normal.y * normal.y)
	+ EMULATE_LIGHT_DIFFUSE_PARAMETER3 * EMULATE_LIGHT_OLD_TOWN_SQUARE_L20 * normal.z * normal.z
	+ EMULATE_LIGHT_DIFFUSE_PARAMETER4 * EMULATE_LIGHT_OLD_TOWN_SQUARE_L00
	- EMULATE_LIGHT_DIFFUSE_PARAMETER5 * EMULATE_LIGHT_OLD_TOWN_SQUARE_L20
	+ 2.0 * EMULATE_LIGHT_DIFFUSE_PARAMETER1 * EMULATE_LIGHT_OLD_TOWN_SQUARE_L2m2 * normal.x * normal.y
	+ 2.0 * EMULATE_LIGHT_DIFFUSE_PARAMETER1 * EMULATE_LIGHT_OLD_TOWN_SQUARE_L21 * normal.x * normal.z
	+ 2.0 * EMULATE_LIGHT_DIFFUSE_PARAMETER1 * EMULATE_LIGHT_OLD_TOWN_SQUARE_L2m1 * normal.y * normal.z
	+ 2.0 * EMULATE_LIGHT_DIFFUSE_PARAMETER2 * EMULATE_LIGHT_OLD_TOWN_SQUARE_L11 * normal.x
	+ 2.0 * EMULATE_LIGHT_DIFFUSE_PARAMETER2 * EMULATE_LIGHT_OLD_TOWN_SQUARE_L1m1 * normal.y
	+ 2.0 * EMULATE_LIGHT_DIFFUSE_PARAMETER2 * EMULATE_LIGHT_OLD_TOWN_SQUARE_L10 * normal.z;

	return color;
}

uniform Matrix matrix;
uniform Material material;

out vec3 fragColor;
out vec2 fragTexcoord;

void main()
{
	vec4 pos = vec4(v_position, 1.0);

	gl_Position = get_mvp(matrix) * pos;

	vec3 normal = matrix.normal * v_normal;
	fragColor = getLightOldTownEmulateDiffuseLight(normal);

	fragTexcoord = v_texcoord;
}