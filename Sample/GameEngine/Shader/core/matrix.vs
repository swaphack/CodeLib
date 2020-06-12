struct Matrix 
{
	mat4 project;	
	mat4 view;
	mat4 model;
};

mat4 get_mvp(Matrix matrix) 
{
	return matrix.project * matrix.view * matrix.model;
}

mat4 get_mv(Matrix matrix) 
{
	return matrix.project * matrix.view;
}