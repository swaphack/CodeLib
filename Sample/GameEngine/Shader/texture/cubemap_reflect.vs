#version 330 core

#include "Shader/core/matrix.vs"
#include "Shader/core/vertex.vs"

uniform Matrix matrix;

out vec3 fragPosition;
out vec3 fragNormal;

void main()
{
	vec4 pos = vec4(v_position, 1.0);
	mat4 mvp = get_mvp(matrix);
	mat4 mv = get_mv(matrix);

	gl_Position = mvp * pos;

	fragNormal = mat3(mv) * v_normal;
	fragPosition = (mv * pos).xyz;
}