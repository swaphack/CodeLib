#version 330 core

#include "Shader/vertex/matrix.vs"
#include "Shader/vertex/vertex.vs"

uniform Matrix matrix;



out vec3 fragmentPosition;
out vec3 fragmentNormal;

void main()
{
	vec4 pos = vec4(v_position, 1.0);
	mat4 mvp = get_mvp(matrix);
	mat4 mv = get_mv(matrix);

	gl_Position = mvp * pos;

	fragmentNormal = mat3(mv) * v_normal;;
	fragmentPosition = (mv * pos).xyz;
}