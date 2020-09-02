struct Matrix 
{
	mat4 project;	// 投影矩阵
	mat4 view;	// 视图矩阵
	mat4 model;	// 模型矩阵
	mat3 normal;	// 法线矩阵
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
vec3 getTransposeNormal(Matrix matrix, vec3 normal)
{
	return normalize(matrix.normal * normal);
}