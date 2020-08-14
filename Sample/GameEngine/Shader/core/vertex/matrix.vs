struct Matrix 
{
	mat4 project;	
	mat4 view;
	mat4 model;
	mat3 normal;
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