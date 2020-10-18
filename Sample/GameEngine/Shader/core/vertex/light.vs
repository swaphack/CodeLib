// 光照空间属性
struct LightSpace
{
	mat4 spaceMatrix; 	// 光照方向的空间矩阵
};


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