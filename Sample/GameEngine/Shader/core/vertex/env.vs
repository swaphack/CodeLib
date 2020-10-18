
// 环境
struct Environment 
{
	vec3 viewPos;	// 视角位置
	int lightCount; // 光源数量
	float gamma;	// gamma值
	float pointSize; // 点大小
};

void setPointSize(Environment env)
{
	gl_PointSize = env.pointSize;
}