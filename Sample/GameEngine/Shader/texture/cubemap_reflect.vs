#version 330 core

#include "Shader/core/vertex/matrix.vs"
#include "Shader/core/vertex/vertex.vs"

uniform Matrix matrix;

out vec3 fragPosition;
out vec3 fragNormal;

void main()
{
	vec4 pos = vec4(v_position, 1.0);
	mat4 mvp = getMVP(matrix);
	mat4 mv = getMV(matrix);

	gl_Position = mvp * pos;

	fragNormal = mat3(mv) * v_normal;
	fragPosition = (mv * pos).xyz;
}