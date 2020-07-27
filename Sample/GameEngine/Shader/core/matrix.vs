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